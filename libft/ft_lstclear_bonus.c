/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:49:49 by atetu             #+#    #+#             */
/*   Updated: 2019/11/17 15:49:36 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *list;
	t_list *prev;

	if (lst == NULL || *lst == NULL)
		return ;
	list = *lst;
	while (list != 0)
	{
		prev = list;
		list = list->next;
		if (prev->content != NULL && del != NULL)
			(*del)(prev->content);
		free(prev);
		prev = 0;
	}
	*lst = 0;
}
