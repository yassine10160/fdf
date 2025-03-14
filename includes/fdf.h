/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:37 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/14 13:37:21 by yafahfou         ###   ########.fr       */
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
# define ZOOM_IN 2
# define ZOOM_OUT 3
# define ZOOM_SPEED 0.05
# define KEY_MINUS 45
# define KEY_PLUS 61
# define ESC_KEY 65307

typedef struct s_point3D
{
	int	x;
	int	y;
	int	z;
	
} t_point3D;

typedef struct s_map
{
	t_point3D 		**values;
	t_point3D		**og_values;
	int			nb_lines;
	int			nb_cols;
	t_point3D	a;
	t_point3D	b;
	int			height;
	int			width;
	int			posx;
	int			posy;
	double		zoom_factor;
	
} t_map;

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
	int			key;
	t_map		*map;
}	t_mlx;

void	free_tab_str(char **split, int count);
void	free_map(t_map *map);
int		absolut(int x);
void	draw_map(t_map *map, t_mlx *fdf);
void	draw_line(t_map *map, t_mlx* fdf);
void	slope_bigger_than_one(t_mlx *fdf, t_point3D *d, t_map *map, int p);
void	slope_less_than_one(t_mlx *fdf, t_point3D *d, t_map *map, int p);
void	set_map(t_map *map, int row, int col, t_mlx *fdf);
void	my_mlx_pixel_put(t_mlx *data, t_point3D *a, int color);
void	parse_map(char *av, t_map *map);
void	isometric(t_point3D *p, double zoom);
void	prepare_map(t_map *map, t_mlx *fdf);
void	set_parse_map(t_map *map, int fd);
int		key_press(int keycode, t_mlx *fdf);
void	alloc_check(void *to_check);
void	stock_map(t_map	*map);
void	open_check(int fd);
int		close_window(t_mlx *fdf);
void	reset_map(t_mlx *fdf);
int		loop_handler(t_mlx *fdf);
int		key_release(int key, t_mlx *fdf);

#endif