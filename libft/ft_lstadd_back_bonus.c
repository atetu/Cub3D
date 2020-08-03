/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:47:58 by atetu             #+#    #+#             */
/*   Updated: 2019/11/17 14:15:02 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	if (!(*alst))
		*alst = new;
	else
	{
		lst = *alst;
		while (lst->next != 0)
			lst = lst->next;
		lst->next = new;
	}
	new->next = 0;
}
