/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:14:09 by atetu             #+#    #+#             */
/*   Updated: 2019/11/13 17:41:57 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s_start, char const *c)
{
	int i;
	int j;

	i = 0;
	while (s_start[i] != 0)
	{
		j = 0;
		while (c[j] != 0 && c[j] != s_start[i])
			j++;
		if (c[j] == 0)
			return (i);
		else if (c[j] == s_start[i])
			i++;
	}
	if (s_start[i] == 0)
		return (-1);
	return (i);
}

static int	ft_end(char const *s_end, char const *c2)
{
	int i;
	int j;

	i = ft_strlen(s_end) - 1;
	while (i >= 0)
	{
		j = 0;
		while ((s_end[i] != c2[j]) && (c2[j] != 0))
			j++;
		if (c2[j] == 0)
			return (i);
		else if (s_end[i] == c2[j])
			i--;
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		index_start;
	int		index_end;
	int		len;
	char	*tmp;

	if (!s1)
		return (0);
	index_start = ft_start(s1, set);
	if (index_start == -1)
		return (str = (char *)ft_calloc(1, 1));
	index_end = ft_end(s1, set);
	len = index_end - index_start + 2;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (0);
	tmp = str;
	while (index_start != index_end)
		*str++ = s1[index_start++];
	*str = s1[index_start];
	str++;
	*str = '\0';
	return (tmp);
}
