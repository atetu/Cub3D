/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:58:03 by atetu             #+#    #+#             */
/*   Updated: 2020/02/20 15:47:58 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_index(char const *s, unsigned int start, unsigned int j)
{
	char			*str;
	char			*tmp;
	unsigned int	size;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (str = (char *)ft_calloc(1, 1));
	size = j - start;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	tmp = str;
	while (s[start] && start < j)
	{
		*str = s[start];
		str++;
		start++;
	}
	*str = '\0';
	return (tmp);
}
