/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:58:00 by yassine           #+#    #+#             */
/*   Updated: 2024/09/27 17:59:58 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ('A' <= (unsigned char)c && (unsigned char)c <= 'Z')
		return (1);
	else if ('a' <= (unsigned char)c && (unsigned char)c <= 'z')
		return (1);
	return (0);
}
