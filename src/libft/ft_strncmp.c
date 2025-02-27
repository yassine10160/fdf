/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:43:01 by yassine           #+#    #+#             */
/*   Updated: 2024/11/06 14:01:23 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1)
	{
		if (!s2)
			return (0);
		return (-(unsigned char)s2[i]);
	}
	else if (!s2)
		return ((unsigned char)s1[i]);
	while (i < n && s1[i] && s2[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char	s1[10] = "Hello";
	char	s2[10] = "Hella";
	printf("ORIGINAL %d\n", strncmp(s1, s2, 10));
	printf("%d\n", ft_strncmp(s1, s2, 10));
	printf("%d\n", ft_strncmp(NULL, s2, 5));
	printf("%d\n", ft_strncmp(NULL, NULL, 5));
	printf("%d\n", ft_strncmp(s1, NULL, 5));
}*/