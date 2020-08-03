/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4bis_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:18:03 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:24:39 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		error_start_map(char c, int i)
{
	if (c == '\0' && i != 1)
	{
		ft_putstr("Error\n: Map should only start on the left with ");
		ft_putstr("a '0', '1', '2' or a space\n");
		return (1);
	}
	return (0);
}

void	which_missing(t_array *array)
{
	if (ft_struct_ok(array))
		ft_putstr("Error\n: Wrong configuration - Missing map\n");
	else
		ft_putstr("Error\n: Missing elements\n");
}

void	putstr_error(char *str)
{
	ft_putstr("Error\n: Invalid expression - ");
	ft_putstr(str);
	ft_putstr("\n");
}

void	putstr_too_many(char *str)
{
	ft_putstr("Error\n: ");
	ft_putstr(str);
	ft_putstr(" - Wrong configuration of the line\n");
}

void	putstr_error_fc(char *arg)
{
	ft_putstr("Error\n: ");
	ft_putstr(arg);
	ft_putstr(" - Only three positive numbers expected, ");
	ft_putstr("separated by commas, without spaces\n");
}
