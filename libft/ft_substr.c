/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:58:03 by atetu             #+#    #+#             */
/*   Updated: 2020/02/03 15:37:46 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*tmp;
	size_t	size;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (str = (char *)ft_calloc(1, 1));
	size = ft_strlen(&s[start]);
	if (size > len)
		size = len;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	tmp = str;
	while (s[start] && len > 0)
	{
		*str = s[start];
		str++;
		start++;
		len--;
	}
	*str = '\0';
	return (tmp);
}
