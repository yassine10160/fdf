/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 18:16:27 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/04 11:11:14 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// need to malloc the right size for the columns and then check valgrind !!!!!!!!!!!!
int main(int ac, char **av)
{
	(void)ac;
	t_mlx	fdf;
	// int		fd;
	t_map	map;

	parse_map(av[1], &map);
	// close(fd);
	fdf.height = 1080;
	fdf.width = 1920;
	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, fdf.width,fdf.height,"FDF");
	fdf.image = mlx_new_image(fdf.mlx, fdf.width, fdf.height);
	fdf.addr = mlx_get_data_addr(fdf.image, &fdf.bpp, &fdf.line_len, &fdf.endian);
	// prepare_map(&map);
	draw_map(&map, &fdf);
	mlx_loop(fdf.mlx);
	free_map(&map);
	return (0);
}
