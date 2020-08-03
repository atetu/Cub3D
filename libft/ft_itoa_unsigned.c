/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:21:38 by atetu             #+#    #+#             */
/*   Updated: 2019/12/08 14:15:52 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_copy(char *array, unsigned int nb, unsigned int pow)
{
	char		*copy;

	copy = array;
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

char			*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	power;
	unsigned int	len;
	unsigned int	nb;
	char			*result;

	power = 1;
	len = 2;
	nb = n;
	while (n > 9)
	{
		n = n / 10;
		power = power * 10;
		len++;
	}
	if (!(result = (char *)malloc(sizeof(char) * (len))))
		return (0);
	result = ft_copy(result, nb, power);
	return (result);
}
