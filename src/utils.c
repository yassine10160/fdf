/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:59:45 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/13 15:44:14 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int absolut(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}


void	free_tab_str(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nb_lines)
	{
		free(map->values[i]);
		i++;
	}
	i = 0;
	while (i < map->nb_lines)
	{
		free(map->og_values[i]);
		i++;
	}
	free(map->values);
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

void	alloc_check(void *to_check)
{
	if (!to_check)
	{
		write(2, "malloc error\n", 13);
		exit(EXIT_FAILURE);
	}
}
