/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:49:10 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/04 16:15:58 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
// erreur makefile pour les .o !!!!!!!!
int	get_height(char *av)
{
	int 	lines;
	char	*gnl;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	gnl = get_next_line(fd);
	if (!gnl)
	{
		write(2, "Error: empty map\n", 17);
		exit(EXIT_FAILURE);
	}
	lines = 0;
	while(gnl)
	{
		lines++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	open_check(int fd)
{
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		exit(EXIT_FAILURE);
	}
}

// ne pas oublier de securiser les mallocs !!!!
void	parse_map(char *av, t_map *map)
{
	int		i;
	int		j;
	char	**split;
	char	*gnl;
	int		fd;

	map->nb_lines = get_height(av);
	fd = open(av, O_RDONLY);
	open_check(fd);
	map->values = malloc(map->nb_lines *sizeof(t_point3D *));
	i = 0;
	while (i < map->nb_lines)
	{
		gnl = get_next_line(fd);
		map->values[i] = malloc(count_word(gnl, ' ') * sizeof(t_point3D));
		map->nb_cols = count_word(gnl, ' ');
		j = -1;
		split = ft_split(gnl, ' ');
		while (++j < count_word(gnl, ' '))
		{
			map->values[i][j].x = i;
			map->values[i][j].y = j;
			map->values[i][j].z = ft_atoi(split[j]);
		}
		free(gnl);
		free_tab_str(split, i);
		i++;
	}
	close(fd);
}

void	my_mlx_pixel_put(t_mlx *data, t_point3D *a, int color)
{
	char	*dst;

	if (a->x < 0 || a->x  >= WIN_WIDTH || a->y < 0 || a->y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (a->x * data->line_len + a->y * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

// recuperer longueur et largeur de la map

// restructurer la fct main , stocker les valeurs dans ma struct et essayer d'afficher une ligne avec la mlx
