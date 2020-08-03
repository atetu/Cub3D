/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:21:38 by atetu             #+#    #+#             */
/*   Updated: 2019/12/08 16:48:13 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_nb(int nbr, int *neg, int *l)
{
	unsigned int	n2;

	if (nbr >= 0)
		n2 = nbr;
	if (nbr < 0)
	{
		*neg = -1;
		n2 = -nbr;
		(*l)++;
	}
	return (n2);
}

static char				*ft_copy(char *array, int *ng, unsigned int nb, int pow)
{
	char		*copy;

	copy = array;
	if (*ng < 0)
	{
		*array = '-';
		array++;
	}
	while (pow != 0)
	{
		*array = nb / pow + 48;
		array++;
		nb = nb % pow;
		pow = pow / 10;
	}
	*array = '\0';
	return (copy);
}

char					*ft_itoa(int n)
{
	int				power;
	int				len;
	int				negative;
	unsigned int	n2;
	char			*result;

	result = NULL;
	power = 1;
	len = 2;
	negative = 1;
	n2 = ft_nb(n, &negative, &len);
	while (n2 > 9)
	{
		n2 = n2 / 10;
		power = power * 10;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len));
	if (!result)
		return (0);
	result = ft_copy(result, &negative, ft_nb(n, &negative, &len), power);
	return (result);
}
