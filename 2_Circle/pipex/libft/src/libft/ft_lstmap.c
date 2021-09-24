/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:15:27 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:28:21 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_curr;
	t_list	*new_next;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	new_curr = new;
	lst = lst->next;
	while (lst)
	{
		new_next = ft_lstnew(f(lst->content));
		if (!new_next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new_curr->next = new_next;
		new_curr = new_curr->next;
		lst = lst->next;
	}
	return (new);
}
