/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:36:15 by yassine           #+#    #+#             */
/*   Updated: 2024/11/09 11:40:48 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_begin(char const *s, char const *set)
{
	size_t	i;
	int		j;
	int		index;

	i = 0;
	while (s[i])
	{
		j = 0;
		index = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				index = 1;
			j++;
		}
		if (!index)
			break ;
		i++;
	}
	return (i);
}

size_t	ft_end(char const *s, char const *set)
{
	size_t	len;
	size_t	i;
	int		index;

	len = ft_strlen(s) - 1;
	while (len > 0)
	{
		i = 0;
		index = 0;
		while (set[i])
		{
			if (s[len] == set[i])
				index = 1;
			i++;
		}
		if (!index)
			break ;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*dest;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set || !s1[0])
		return (ft_strdup(s1));
	begin = ft_begin(s1, set);
	end = ft_end(s1, set);
	if (begin > end)
		return (ft_strdup(""));
	dest = malloc ((end - begin + 2) * sizeof(char));
	if (!dest)
		return (NULL);
	while (begin + i <= end)
	{
		dest[i] = s1[begin + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main()
{
	char	*set = ". ";
	char	*str = "";
	printf("%s\n", ft_strtrim(str, set));
	printf("%s\n", ft_strtrim("a", "ab"));
}*/