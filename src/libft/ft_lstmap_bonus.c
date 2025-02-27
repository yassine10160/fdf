/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yassinefahfouhi <yassinefahfouhi@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:45:30 by yassinefahf       #+#    #+#             */
/*   Updated: 2024/11/04 14:51:46 by yassinefahf      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst;
	void	*tmp;

	if (!lst || !f)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		tmp = (*f)(lst->content);
		tmp_lst = ft_lstnew(tmp);
		if (!tmp_lst)
		{
			del(tmp);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst->next;
	}
	return (new_lst);
}
