/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:47:15 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/14 13:46:01 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int close_window(t_mlx *fdf)
{
	write(1, "Window closed\n", 14);
	mlx_destroy_window(fdf->mlx, fdf->window);
	exit(0);
	return (0);
}

int key_press(int keycode, t_mlx *fdf)
{
	// fdf->map->zoom_factor = 50;
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fdf->mlx, fdf->window);
		exit(0);
	}
	// printf("mymap: %d", fdf->map->nb_cols);
	if (keycode == KEY_PLUS)
	{
		fdf->map->zoom_factor *= 1.2;
		fdf->key = keycode;
		reset_map(fdf);
		return (ZOOM_IN);
	}
	if (keycode == KEY_MINUS)
	{
		fdf->map->zoom_factor *= 0.8;
		fdf->key = keycode;
		reset_map(fdf);
		return (ZOOM_OUT);
	}
	return (0);
}

// int	loop_handler(t_mlx *fdf)
// {
// 	if (fdf->key == KEY_PLUS)
// 		fdf->map->zoom_factor += ZOOM_SPEED;
// 	if (fdf->key == KEY_MINUS)
// 		fdf->map->zoom_factor -= ZOOM_SPEED;
// 	if (fdf->map->zoom_factor < 0.1)
// 		fdf->map->zoom_factor = 0.1;
// 	reset_map(fdf);
// 	return (0);
// }

void reset_map(t_mlx *fdf)
{
	if (fdf->image)
        mlx_destroy_image(fdf->mlx, fdf->image);
    fdf->image= mlx_new_image(fdf->mlx, fdf->width, fdf->height);
    fdf->addr = mlx_get_data_addr(fdf->image, &fdf->bpp, &fdf->line_len, &fdf->endian);
    draw_map(fdf->map, fdf);
	
    // mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image, 0, 0);
}

// int key_release(int key, t_mlx *fdf)
// {
// 	if (key == KEY_PLUS || key == KEY_MINUS)
		
// }