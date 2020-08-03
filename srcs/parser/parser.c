/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:26:16 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 17:39:34 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_parser_dir_data(char **line, t_array *array)
{
	char	data;

	data = '0';
	*line = move_isspace(*line);
	if (ft_parser_dir_no(line, array, &data) == -1)
		return (-1);
	if (data == '0')
		if (ft_parser_dir_so_p(line, array, &data) == -1)
			return (-1);
	if (data == '0')
		if (ft_parser_dir_we(line, array, &data) == -1)
			return (-1);
	if (data == '0')
	{
		if (ft_parser_dir_ea(line, array, &data) == -1)
			return (-1);
	}
	if (data != '0')
		return (1);
	return (0);
}

int		check_nothing_more(char c, char *str)
{
	if (c != '\0' && c != '\n')
	{
		putstr_too_many(str);
		return (0);
	}
	return (1);
}

int		parser_resolution(char **line, t_array *array, char *arg, char *nb)
{
	*line = move_isspace(*line);
	if (**line != 'R')
		return (0);
	(*line)++;
	if ((check_beginning(*line, array->resolution, "Resolution", array)) == -1)
		return (-1);
	if (ft_isspace(**line))
	{
		*line = move_isspace(*line);
		if (check_dig_arg(&(*line), &array->resolution_x, arg, nb) == -1)
			return (-1);
		if (!(ft_check_isspace(*line, "Resolution")))
			return (-1);
		*line = move_isspace(*line);
		if (check_dig_arg(&(*line), &array->resolution_y, arg, nb) == -1)
			return (-1);
		*line = move_isspace(*line);
		if (!(check_nothing_more(**line, "Resolution")))
			return (-1);
		array->resolution = 1;
		return (0);
	}
	putstr_error("Resolution");
	return (-1);
}

int		parser(char **str, t_array *array)
{
	char	*line;
	int		result;

	line = *str;
	result = ft_parser_dir_data(&line, array);
	if (result == -1)
		return (-1);
	else if (result == 1)
		return (1);
	else
	{
		result = parser_resolution(&line, array, "Resolution", "two");
		if (result == -1)
			return (-1);
		else if (result == 1)
			return (1);
		else
		{
			if (parser_ceiling_floor_data(&line, array) == -1)
				return (-1);
		}
	}
	return (0);
}
