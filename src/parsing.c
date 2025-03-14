/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:49:10 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/13 15:46:33 by yafahfou         ###   ########.fr       */
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

// ne pas oublier de securiser les mallocs !!!!
void	parse_map(char *av, t_map *map)
{
	int		fd;

	map->nb_lines = get_height(av);
	fd = open(av, O_RDONLY);
	open_check(fd);
	map->values = malloc(map->nb_lines *sizeof(t_point3D *));
	alloc_check(map->values);
	set_parse_map(map, fd);
}

void	set_parse_map(t_map *map, int fd)
{
	int	i;
	char	**split;
	char	*gnl;
	int		j;

	i = -1;
	while (++i < map->nb_lines)
	{
		gnl = get_next_line(fd);
		map->values[i] = malloc(count_word(gnl, ' ') * sizeof(t_point3D));
		alloc_check(map->values[i]);
		map->nb_cols = count_word(gnl, ' ');
		j = -1;
		split = ft_split(gnl, ' ');
		while (++j < count_word(gnl, ' '))
		{
			map->values[i][j].x = j;
			map->values[i][j].y = i;
			map->values[i][j].z = ft_atoi(split[j]);
		}
		free(gnl);
		free_tab_str(split, i);
	}
	close(fd);
}

void	stock_map(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	map->og_values = malloc(map->nb_lines * sizeof(t_point3D *));
	alloc_check(map->values);
	while (i < map->nb_lines)
	{
		j = 0;
		map->og_values[i] = malloc((map->nb_cols) * sizeof(t_point3D));
		// printf("je suis la\n");
		alloc_check(map->og_values[i]);
		while (j < map->nb_cols)
		{
			map->og_values[i][j].x = j;
			map->og_values[i][j].y = i;
			map->og_values[i][j].z = map->values[i][j].z;
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_mlx *data, t_point3D *a, int color)
{
	char	*dst;

	if (a->x < 0 || a->x  >= WIN_WIDTH || a->y < 0 || a->y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (a->y * data->line_len + a->x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
