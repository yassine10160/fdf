/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:47:15 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/20 13:50:35 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, t_mlx *fdf)
{
	if (keycode == ESC_KEY)
	{
		close_window(fdf);
		exit(0);
	}
	if (keycode == KEY_PLUS)
	{
		fdf->map->zf *= 1.2;
		if (fdf->map->zf > 100)
			fdf->map->zf = 100;
		fdf->key = keycode;
		reset_map(fdf);
		return (ZOOM_IN);
	}
	if (keycode == KEY_MINUS)
	{
		fdf->map->zf *= 0.8;
		if (fdf->map->zf < 2.5)
			fdf->map->zf = 2.5;
		fdf->key = keycode;
		reset_map(fdf);
		return (ZOOM_OUT);
	}
	return (0);
}

void	reset_map(t_mlx *fdf)
{
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, fdf->width, fdf->height);
	fdf->addr
		= mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->l_len, &fdf->end);
	draw_map(fdf->map, fdf);
}

int	close_window(t_mlx *fdf)
{
	write(1, "Window closed\n", 14);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	if (fdf->window)
		mlx_destroy_window(fdf->mlx, fdf->window);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	if (fdf->mlx)
		free(fdf->mlx);
	if (fdf->map)
		free_map(fdf->map, BOTH);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_mlx *data, t_point3D *a, int color)
{
	char	*dst;

	if (a->x < 0 || a->x >= WIN_WIDTH || a->y < 0 || a->y >= WIN_HEIGHT)
		return ;
	dst = data->addr + (a->y * data->l_len + a->x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
