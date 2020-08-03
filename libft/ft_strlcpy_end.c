/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:41:09 by atetu             #+#    #+#             */
/*   Updated: 2019/12/08 14:14:13 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy_end(char *dst, char *src, int index, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	tmp = dst;
	while (len--)
		dst[index++] = src[i++];
	return (tmp);
}
