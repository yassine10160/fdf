/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:27 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/20 13:50:18 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_mlx	fdf;
	t_map	map;

	if (ac == 2)
	{
		parse_map(av[1], &map);
		stock_og_values(&map);
		fdf.height = 1080;
		fdf.width = 1920;
		fdf.mlx = mlx_init();
		fdf.window = mlx_new_window(fdf.mlx, fdf.width, fdf.height, "FDF");
		fdf.img = mlx_new_image(fdf.mlx, fdf.width, fdf.height);
		fdf.addr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.l_len, &fdf.end);
		fdf.map = &map;
		fdf.key = -1;
		calculate_zoom(&map);
		draw_map(&map, &fdf);
		mlx_hook(fdf.window, 17, 0, close_window, &fdf);
		mlx_key_hook(fdf.window, key_press, &fdf);
		mlx_loop(fdf.mlx);
		free_map(&map, BOTH);
	}
	else
		write(2, "Too many arguments\n", 19);
	return (0);
}
