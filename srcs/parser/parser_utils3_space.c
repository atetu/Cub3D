/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:42:49 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:41:47 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*move_isspace(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

int		ft_check_isspace_beginning(t_array *array, char *str, char *arg)
{
	int i;

	if (!(ft_isspace(*str)) && *str != '\0' && (!(ft_struct_ok(array))))
	{
		i = 1;
		while (str[i] != '\0' && check_char_map(str[i]))
			i++;
		if (error_wrong_conf_wmap(str[i], i))
			return (0);
		error_wrong_line_configuration(arg);
		return (0);
	}
	else if (!(ft_isspace(*str)) && *str != '\0' && ft_struct_ok(array))
	{
		i = 1;
		while (str[i] != '\0' && check_char_map(str[i]))
			i++;
		if (error_start_map(str[i], i))
			return (0);
		ft_putstr("Error\n: Wrong line in the file\n");
		return (0);
	}
	return (1);
}

int		ft_check_isspace(char *str, char *arg)
{
	if (!(ft_isspace(*str)) && *str != '\0')
	{
		ft_putstr("Error\n: Invalid expression - ");
		ft_putstr(arg);
		ft_putstr("\n");
		return (0);
	}
	else
		return (1);
}

int		ft_check_isspace_map(char *str)
{
	if (!(ft_isspace(*str)) && *str != '\0')
	{
		ft_putstr("Error\n: Bad spacing in the map\n");
		return (0);
	}
	else
		return (1);
}

int		check_space(char c)
{
	if (c != '\0')
	{
		ft_putstr("Error\n: Bad spacing in the map\n");
		return (0);
	}
	return (1);
}
