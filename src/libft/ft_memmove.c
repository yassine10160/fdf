/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:33:28 by yassine           #+#    #+#             */
/*   Updated: 2024/11/05 13:29:12 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_src;
	unsigned char	*temp_dest;

	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (!temp_dest || !temp_src)
		return (NULL);
	if ((size_t)(dest) - (size_t)(src) <= n)
	{
		while (n-- > 0)
			temp_dest[n] = temp_src[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			temp_dest[i] = temp_src[i];
	}
	return (dest);
}
