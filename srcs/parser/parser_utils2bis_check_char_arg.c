/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2bis_check_char_argc.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:52:03 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 15:18:16 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		error_wrong_line(char **line, t_array *array)
{
	while ((**line) != '\0')
	{
		if ((**line) != '0' && (**line) != '1' && (**line) != '2'
				&& (**line) != 'N' && (**line) != 'S'
				&& (**line) != 'E' && (**line) != 'W'
				&& !(ft_isspace((**line))))
		{
			ft_putstr("Error\n: Wrong line in the file\n");
			return (1);
		}
		(*line)++;
	}
	if (!(ft_struct_ok(array)))
		error_wrong_configuration();
	else
	{
		ft_putstr("Error\n: Map should only start on the left with a ");
		ft_putstr("'0', '1', '2', or a space\n");
	}
	return (1);
}

int		check_char_dir(char c, char expected, char *data, char given_data)
{
	if (c == expected)
	{
		*data = given_data;
		return (1);
	}
	return (0);
}

int		end_line_ok(char *data, t_array *array, char **line, int i)
{
	if (!(ft_check_conflicting_arg_south_sprites(data, array)))
		return (0);
	if (ft_fill_south_sprite(data, array, line, i) == -1)
		return (0);
	return (1);
}
