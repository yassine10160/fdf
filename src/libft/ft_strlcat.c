/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:54:14 by yassine           #+#    #+#             */
/*   Updated: 2024/11/06 17:24:00 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_d;

	len_d = ft_strlen(dest);
	if (size == 0)
		return (ft_strlen(src));
	i = len_d;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dest[i] = '\0';
	if (size < len_d)
		return (ft_strlen(src) + size);
	else
		return (len_d + ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	buff1[10] = "Hello";
	char	buff2[10] = "World";
	char	buff3[10] = "Hello";
	
	printf("ORIGINAL %ld\n",strlcat(buff1, buff2, 10));
	printf("%ld", ft_strlcat(buff3, buff2, 10));
	// printf("ORIGINAL %ld\n",strlcat(buff1, NULL, 10));
	// printf("%ld", ft_strlcat(buff3, NULL, 10));
}*/
