/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:48:18 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/11/04 15:40:23 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	next = *lst;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}
/*
void	ft_del(void *content)
{
	free(content);
}

#include <stdio.h>
int	main()
{
	t_list	*head = (t_list *)malloc(sizeof(t_list));
	head->content = malloc(sizeof(int));
	*(int *)head->content = 1;
	head->next = (t_list *)malloc(sizeof(t_list));
	head->next->content = malloc(sizeof(int));
	*(int *)head->next->content = 2;
	head->next->next = (t_list *)malloc(sizeof(t_list));
	head->next->next->content = malloc(sizeof(int));
	*(int *)head->next->next->content = 3;
	head->next->next->next = (t_list *)malloc(sizeof(t_list));
	head->next->next->next->content = malloc(sizeof(int));
	*(int *)head->next->next->next->content = 4;
	head->next->next->next->next = NULL;
	printf("avant application: \n");
	t_list	*tmp = head;
	while(tmp)
	{
		printf("contenu: %d\n", *(int *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstclear(&head,ft_del);
	if (head == NULL)
		printf("succes\n");
	else
		printf("echec\n");
	return (0);
}
*/
