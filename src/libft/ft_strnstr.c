/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassine <yassine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:39:14 by yassine           #+#    #+#             */
/*   Updated: 2024/10/02 16:56:57 by yassine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		if (big[i] == little[0])
		{
			index = i;
			j = 0;
			while (big[index] == little[j] && index < len)
			{
				if (little[j + 1] == '\0')
					return ((char *)(big + i));
				index++;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main()
{
	char	buf[30] = "hello world hhow are you";
	char	buf2[10] = "hhow";
	printf ("%s", ft_strnstr(buf, buf2, 30));
}*/