/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 21:45:22 by yassine           #+#    #+#             */
/*   Updated: 2024/10/13 21:53:05 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ui;
	char			c;

	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	ui = n;
	if (ui < 10)
	{
		c = ui + 48;
		write(fd, &c, 1);
	}
	else if (ui > 9)
	{
		ft_putnbr_fd(ui / 10, fd);
		ft_putnbr_fd(ui % 10, fd);
	}
}
