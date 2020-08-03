/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:44:56 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:50:19 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		check_existing_map(int row, char c)
{
	if (row == 0 && c == '\0')
	{
		ft_putstr("Error\n: Missing map\n");
		return (0);
	}
	return (-1);
}

int		wrong_char(t_array *array, char c, char *line)
{
	if ((ft_struct_ok(array) && !(array->flag_map) && c != '1' && c != '2'
				&& c != '0') || (!(ft_struct_ok(array))))
	{
		if (c != '1' && c != '2' && c != '0')
		{
			ft_putstr("Error\n: Wrong line the file\n");
			return (1);
		}
		else
		{
			while (*line && check_char_map(*line))
				line++;
			if (*line == 0)
			{
				error_wrong_configuration();
				return (1);
			}
			else
			{
				ft_putstr("Error\n: Wrong line the file\n");
				return (1);
			}
		}
	}
	return (0);
}

int		ft_correct_char(char c, char expected_c, char *arg)
{
	if (c == expected_c)
		return (1);
	else
	{
		putstr_error_fc(arg);
		return (0);
	}
}

int		ft_check_conflicting_arg(int nb, char *str)
{
	if (nb == 1)
	{
		ft_putstr("Error\n: Conflicting arguments - ");
		ft_putstr(str);
		ft_putstr("\n");
		return (0);
	}
	return (1);
}

int		ft_check_conflicting_arg_str(char *arg, char *str)
{
	if (arg != NULL)
	{
		ft_putstr("Error\n: Conflicting arguments - ");
		ft_putstr(str);
		ft_putstr("\n");
		return (0);
	}
	return (1);
}
