/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:01:37 by yafahfou          #+#    #+#             */
/*   Updated: 2025/02/27 11:58:33 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "../minilibx-linux/mlx.h"
#include "libft/libft.h"

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

typedef struct s_map
{
	int **height;
	int	nb_lines;
	int	*nb_cols;
} t_map;

typedef struct s_point2D
{
	int	x;
	int	y;
	
} t_point2D;

#endif