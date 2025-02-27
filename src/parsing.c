/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:49:10 by yafahfou          #+#    #+#             */
/*   Updated: 2025/02/27 13:28:50 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		free(map->height[i]);
		i++;
	}
	free(map->height);
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
	map->height = malloc(map->nb_lines *sizeof(int *));
	i = 0;
	while (i < map->nb_lines)
	{
		gnl = get_next_line(fd);
		map->height[i] = malloc(count_word(gnl, ' ') * sizeof(int));
		// printf("nb_lines: %d\n", map->nb_lines);
		// map->nb_cols[i] = count_word(gnl, ' ');
		j = -1;
		split = ft_split(gnl, ' ');
		while (++j < count_word(gnl, ' '))
			map->height[i][j] = ft_atoi(split[j]);
		free(gnl);
		free_tab_str(split, i);
		i++;
	}
	close(fd);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

// void	draw_line(t_mlx m, int x, int y)
// {

// 	while (x <= 800 && y <= 500)
// 	{
// 		my_mlx_pixel_put(&m, x, y, 0x00FF0000);
// 		mlx_put_image_to_window(m.mlx, m.window,m.image, 96, 50);
// 		x++;
// 		y++;
// 	}

// }
int absolut(int x)
{
	if ( x < 0)
		return (-x);
	return (x);
}

void draw_line(t_mlx m, t_point2D *a, t_point2D *b)
{
	t_point2D	d;

	d.x = b->x - a->x;
	d.y = b->y - a->y;
	if (absolut(d.x) > absolut(d.y))
		slope_less_than_one(m, d, a ,b);
	else
		slope_bigger_than_one(m, d, a, b);
}

void slope_less_than_one(t_mlx m, t_point2D d, t_point2D *a, t_point2D *b)
{
	int p;
	int	i;

	i = -1;
	p = 2 *absolut(d.y) - absolut(d.x);
	my_mlx_pixel_put(&m, a->x, a->y, 0x00FF0000);
	while (++i < absolut(d.x))
	{
		if (d.x > 0)
			a->x++;
		else
			a->x--;
		if (p < 0)
			p = p + 2 * absolut(d.y);
		else
		{
			if (d.y > 0)
				a->y++;
			else
				a->y--;
			p = p + 2 *absolut(d.y) - 2 * absolut(d.x);
		}
		my_mlx_pixel_put(&m, a->x, a->y, 0x00FF0000);
	}
}

void slope_bigger_than_one(t_mlx m, t_point2D d, t_point2D *a, t_point2D *b)
{
	int	p;
	int	i;

	i = -1;
	p = 2 *absolut(d.x) - absolut(d.y);
	my_mlx_pixel_put(&m, a->x, a->y, 0x00FF0000);
	while (++i < absolut(d.y))
	{
		if (d.y > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p = p + 2 * absolut(d.x);
		else
		{
			if (d.x > 0)
				a->x++;
			else
				a->x--;
			p = p + 2 *absolut(d.x) - 2 * absolut(d.y);
		}
		my_mlx_pixel_put(&m, a->x, a->y, 0x00FF0000);
	}
}

// void	pre_map(t_map *a, t_point2D *b)
// {
// 	a->x *= 50;
// 	b->x *= 50;
// 	a->y *= 50;
// 	b->y = 50;
// 	a->z = 50;
// }

// need to malloc the right size for the columns and then check valgrind !!!!!!!!!!!!
int main(int ac, char **av)
{
	(void)ac;
	t_mlx	m;
	// int		fd;
	t_map	map;

	parse_map(av[1], &map);
	// close(fd);
	free_map(&map);
	m.height = 1080;
	m.width = 1920;
	m.mlx = mlx_init();
	m.window = mlx_new_window(m.mlx, m.width,m.height,"FDF");
	m.image = mlx_new_image(m.mlx, m.width, m.height);
	m.addr = mlx_get_data_addr(m.image, &m.bpp, &m.line_len, &m.endian);
	draw_line(m);
	mlx_loop(m.mlx);
	return (0);
}
// restructurer la fct main , stocker les valeurs dans ma struct et essayer d'afficher une ligne avec la mlx
