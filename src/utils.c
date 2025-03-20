/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:59:45 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/19 18:26:48 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	absolut(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	free_tab_str(char **split, int count, char *gnl)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (gnl)
		free(gnl);
}

void	free_map(t_map *map, int mode)
{
	int	i;

	i = 0;
	while (map->values && i < map->nb_lines)
	{
		free(map->values[i]);
		i++;
	}
	i = 0;
	while (mode != ONLY_VALUES && map->og_values && i < map->nb_lines)
	{
		free(map->og_values[i]);
		i++;
	}
	if (map->values)
		free(map->values);
	if (mode != ONLY_VALUES && map->og_values)
		free(map->og_values);
}

void	open_check(int fd)
{
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		exit(EXIT_FAILURE);
	}
}

void	alloc_check(void *to_check, t_map *map)
{
	if (map->values && !to_check)
		free_map(map, ONLY_VALUES);
	if (!to_check)
	{
		write(2, "malloc error\n", 13);
		exit(EXIT_FAILURE);
	}
}
