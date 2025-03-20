/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:49:10 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/20 13:45:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_height(char *av, t_map *map)
{
	int		lines;
	char	*gnl;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	gnl = get_next_line(fd);
	map->nb_cols = calc_nb_words(gnl, " ");
	if (!gnl)
	{
		write(2, "Error: empty map\n", 17);
		exit(EXIT_FAILURE);
	}
	lines = 0;
	while (gnl)
	{
		lines++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

void	parse_map(char *av, t_map *map)
{
	int		fd;

	map->nb_lines = get_height(av, map);
	fd = open(av, O_RDONLY);
	open_check(fd);
	map->values = malloc(map->nb_lines * sizeof(t_point3D *));
	alloc_check(map->values, map);
	set_parse_map(map, fd);
	close(fd);
}

void	check_col_nb(t_map *map, int col, char *gnl, int fd)
{
	if (col != map->nb_cols)
	{
		if (gnl)
			free(gnl);
		write(2, "Invalid map\n", 12);
		free_map(map, ONLY_VALUES);
		close(fd);
		exit(1);
	}
	else if (!gnl)
	{
		free_map(map, ONLY_VALUES);
		close(fd);
		exit(1);
	}
	map->nb_cols = col;
	return ;
}

void	set_parse_map(t_map *map, int fd)
{
	int		i;
	char	**split;
	char	*gnl;
	int		j;
	int		nb_words;

	i = -1;
	while (++i < map->nb_lines)
	{
		gnl = get_next_line(fd);
		nb_words = calc_nb_words(gnl, " ");
		map->values[i] = malloc(nb_words * sizeof(t_point3D));
		alloc_check(map->values[i], map);
		check_col_nb(map, nb_words, gnl, fd);
		j = -1;
		split = ft_split(gnl, " ");
		alloc_check(split, map);
		while (++j < nb_words)
		{
			map->values[i][j].x = j;
			map->values[i][j].y = i;
			map->values[i][j].z = ft_atoi(split[j]);
		}
		free_tab_str(split, j, gnl);
	}
}

void	stock_og_values(t_map	*map)
{
	int	i;
	int	j;

	i = 0;
	map->og_values = malloc(map->nb_lines * sizeof(t_point3D *));
	alloc_check(map->values, map);
	while (i < map->nb_lines)
	{
		j = 0;
		map->og_values[i] = malloc((map->nb_cols) * sizeof(t_point3D));
		alloc_check(map->og_values[i], map);
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
