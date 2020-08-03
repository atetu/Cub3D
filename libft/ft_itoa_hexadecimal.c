/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:21:38 by atetu             #+#    #+#             */
/*   Updated: 2019/12/08 15:28:11 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long int	ft_size_array(unsigned long int nbr)
{
	unsigned long int size;

	size = 0;
	if (nbr > 15)
	{
		while ((nbr / 16) != 0)
		{
			nbr = nbr / 16;
			size++;
		}
	}
	if (nbr <= 15)
		size++;
	size++;
	return (size);
}

static char					*ft_copy(char c, char *ar)
{
	int i;

	i = 0;
	while (ar[i] != '\0')
		i++;
	ar[i] = c;
	i++;
	ar[i] = '\0';
	return (ar);
}

static char					*ft_putnbr_base(unsigned long int nbr, char *base,
		unsigned int size_base, char *array)
{
	char character;

	if (nbr >= size_base)
	{
		ft_putnbr_base((nbr / size_base), base, size_base, array);
		ft_putnbr_base((nbr % size_base), base, size_base, array);
	}
	else
	{
		character = base[nbr];
		array = ft_copy(character, array);
	}
	return (array);
}

char						*ft_itoa_hexadecimal(unsigned long int n, char c)
{
	unsigned long int	power;
	unsigned long int	len;
	char				*result;
	char				*base;

	result = NULL;
	base = NULL;
	power = 1;
	len = 2;
	if (!(base = (char *)malloc(sizeof(char) * 17)))
		return (0);
	if (c == 'x')
		ft_strlcpy(base, "0123456789abcdef", 17);
	else if (c == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", 17);
	len = ft_size_array(n);
	if (!(result = calloc(sizeof(char), len)))
		return (0);
	result = ft_putnbr_base(n, base, 16, result);
	if (base != NULL)
		free(base);
	return (result);
}
