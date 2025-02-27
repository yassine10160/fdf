/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:36:03 by yassine           #+#    #+#             */
/*   Updated: 2024/09/29 17:57:37 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(src);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (len_s);
}
/*
#include <bsd/string.h>
#include <stdio.h>

int main()
{
	char	buff1[21] = "Bonjour tout le monde";
	char	buff2[21];
	char	buff3[21];
	
	printf("ORIGINAL %zu", strlcpy(buff2, buff1, 0));
	printf(" %s\n",buff2);
	printf("%zu", ft_strlcpy(buff3, buff1, 0));
	printf(" %s", buff3);
	return (0);
}*/