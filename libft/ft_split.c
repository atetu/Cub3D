/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:07:35 by atetu             #+#    #+#             */
/*   Updated: 2019/11/15 17:44:01 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *str, char c1)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str == c1 && *str)
		{
			str++;
			if (*str != c1 && *str != '\0')
				count++;
			if (*str == '\0' && count == 0)
				return (0);
		}
		while (*str != c1 && *str)
			str++;
	}
	if (count == 0)
		return (1);
	else
		return (count + 1);
}

static int	ft_copy(const char *src, char c2, char *ar)
{
	int count3;

	count3 = 0;
	while (*src != c2 && *src != 0)
	{
		*ar = *src;
		ar++;
		src++;
		count3++;
	}
	*ar = '\0';
	while (*src == c2 && *src != '\0')
	{
		src++;
		count3++;
	}
	return (count3);
}

static int	ft_count(char const *s1, char c3)
{
	int		count2;

	count2 = 1;
	while (*s1 != c3 && *s1 != '\0')
	{
		count2++;
		s1++;
	}
	return (count2);
}

char		**ft_split(char const *s, char c)
{
	char		**array;
	int			i;
	int			count4;

	if (!s)
		return (0);
	i = 0;
	if (!(array = malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (0);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (!(array[i] = (char *)malloc(sizeof(char) * ft_count(s, c))))
			return (0);
		count4 = ft_copy(s, c, array[i]);
		while (count4--)
			s++;
		i++;
	}
	array[i] = 0;
	return (&array[0]);
}
