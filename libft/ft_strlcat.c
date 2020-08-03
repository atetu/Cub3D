/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:32:50 by atetu             #+#    #+#             */
/*   Updated: 2019/11/17 15:11:21 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dlen;
	unsigned int	slen;
	char			*d;
	char			*s;

	d = dst;
	s = (char *)src;
	dlen = 0;
	slen = 0;
	if (!dst && !dstsize)
		return (ft_strlen(src));
	while (s[slen])
		slen++;
	while (*d)
	{
		d++;
		if ((unsigned long)(d - dst) >= dstsize)
			return (dstsize + slen);
	}
	dlen = d - dst;
	while (*s && (unsigned long)(d - dst) < dstsize - 1)
		*d++ = *s++;
	*d = 0;
	return (slen + dlen);
}
