/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:05:07 by atetu             #+#    #+#             */
/*   Updated: 2019/11/16 11:16:48 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!(dst) && !(src))
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n != 0)
	{
		*d = *s;
		d++;
		s++;
		n--;
	}
	return (dst);
}
