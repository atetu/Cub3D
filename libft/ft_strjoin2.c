/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:34:58 by atetu             #+#    #+#             */
/*   Updated: 2020/01/31 10:35:25 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char *s1, char *s2, size_t i)
{
	size_t	len_str;
	char	*str;
	char	*tmp;
	size_t	j;

	j = 0;
	len_str = ft_strlen(s1) + i + 1;
	if (!(str = (char *)malloc(sizeof(char) * len_str)))
		return (0);
	tmp = str;
	if (s1)
	{
		while (*s1)
			*str++ = *s1++;
	}
	while (j < i)
		*str++ = s2[j++];
	*str = '\0';
	return (tmp);
}
