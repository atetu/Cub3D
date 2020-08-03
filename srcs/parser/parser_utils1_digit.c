/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:42:49 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 17:04:51 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_atoi_digit(char *str, int *n)
{
	int		nb;

	nb = 0;
	if (!ft_isdigit(*str))
	{
		ft_putstr("Error\n: Wrong expression - ");
		return (NULL);
	}
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	*n = nb;
	return (str);
}

char	*ft_atoi_digit_fc(char *str, int *n, char *arg)
{
	int		nb;

	nb = 0;
	if (!ft_isdigit(*str))
	{
		ft_putstr("Error\n: ");
		ft_putstr(arg);
		ft_putstr(" - Only three positive numbers expected, ");
		ft_putstr("separated by commas, without spaces\n");
		return (NULL);
	}
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + (*str - 48);
		str++;
	}
	*n = nb;
	return (str);
}

int		check_dig_arg(char **line, int *n, char *arg, char *nb)
{
	if (((*line = ft_atoi_digit(*line, n)) == NULL))
	{
		ft_putstr(arg);
		ft_putstr(": Only ");
		ft_putstr(nb);
		ft_putstr(" positive numbers expected, ");
		ft_putstr("separated by spaces\n");
		return (-1);
	}
	return (0);
}
