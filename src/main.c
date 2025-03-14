/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:27 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/14 13:46:41 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// need to malloc the right size for the columns and then check valgrind !!!!!!!!!!!!
// void	redraw_map(t_mlx *fdf)
// {
	
// }

// gerer le zoom et dezoom: avoir un facteur zoom dans ma structure, des que la touche
//- ou + est activee, je decremente zoom et je  redraw_map avec le nouveau_zoom

int main(int ac, char **av)
{
	(void)ac;
	t_mlx	fdf;
	// int		fd;
	t_map	map;

	parse_map(av[1], &map);
	stock_map(&map);
	// close(fd);
	fdf.height = 1080;
	fdf.width = 1920;
	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, fdf.width,fdf.height,"FDF");
	fdf.image = mlx_new_image(fdf.mlx, fdf.width, fdf.height);
	fdf.addr = mlx_get_data_addr(fdf.image, &fdf.bpp, &fdf.line_len, &fdf.endian);
	fdf.map = &map;
	fdf.map->zoom_factor = 50;
	draw_map(&map, &fdf);
	mlx_key_hook(fdf.window, key_press, &fdf);
	mlx_hook(fdf.window, 17, 0, close_window, &fdf);
	// mlx_hook(fdf.window, 3, 1L<<1, key_release, &fdf);
	// mlx_loop_hook(fdf.mlx, loop_handler, &fdf);
	mlx_loop(fdf.mlx);
	free_map(&map);
	return (0);
}
