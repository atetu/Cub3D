/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:38:06 by atetu             #+#    #+#             */
/*   Updated: 2019/11/16 10:22:44 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)s;
	while (n != 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}
