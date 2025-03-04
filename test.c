/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yafahfou <yafahfou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:30:01 by yafahfou          #+#    #+#             */
/*   Updated: 2025/03/01 15:35:59 by yafahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*test(char *str)
{
	static char dest[5];
	dest = str;
	return (dest);
}

int main()
{
	printf("%s", test("salut"));
}