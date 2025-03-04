/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:37 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/04 15:23:51 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "../src/libft/libft.h"
#include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define STEP 50

typedef struct s_mlx
{
	void*		mlx;
	void*		window;
	void*		image;
	char*		addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}	t_mlx;

typedef struct s_point3D
{
	int	x;
	int	y;
	int	z;
	
} t_point3D;

typedef struct s_map
{
	t_point3D 		**values;
	int			nb_lines;
	int			nb_cols;
	t_point3D	a;
	t_point3D	b;
	int			height;
	int			width;
	int			posx;
	int			posy;
	
} t_map;

void	free_tab_str(char **split, int count);
void	free_map(t_map *map);
int		absolut(int x);
void	draw_map(t_map *map, t_mlx *fdf);
void	draw_line(t_map *map, t_mlx* fdf);
void	slope_bigger_than_one(t_mlx *fdf, t_point3D *d, t_map *map);
void	slope_less_than_one(t_mlx *fdf, t_point3D *d, t_map *map);
void	set_map(t_map *map, int row, int col);
void	my_mlx_pixel_put(t_mlx *data, t_point3D *a, int color);
void	parse_map(char *av, t_map *map);
// void	isometric(t_map *map);
void	isometric(t_point3D *p);
void	prepare_map(t_map *map);
#endif