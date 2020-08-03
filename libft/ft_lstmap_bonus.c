/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:18:22 by atetu             #+#    #+#             */
/*   Updated: 2019/11/17 15:46:13 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *element;

	if (!(lst) || !(f))
		return (0);
	new_list = ft_lstnew((*f)(lst->content));
	element = new_list;
	while (lst->next != 0)
	{
		lst = lst->next;
		element->next = ft_lstnew((*f)(lst->content));
		if (!(element->next))
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		element = element->next;
	}
	element->next = 0;
	return (new_list);
}
