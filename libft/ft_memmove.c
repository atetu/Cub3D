/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:58:41 by atetu             #+#    #+#             */
/*   Updated: 2019/11/17 15:38:58 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	const char	*s_end;
	char		*d;
	char		*d_end;

	s = src;
	d = dst;
	if (d == 0 && s == 0)
		return (dst);
	s_end = s + len - 1;
	d_end = d + len - 1;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		while (len--)
			*d_end-- = *s_end--;
	}
	return (dst);
}
