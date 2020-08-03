/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ceiling_floor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:40:43 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:56:11 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_check_range_colors(int red, int green, int blue)
{
	if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0
			|| blue > 255)
	{
		ft_putstr("Error\n: Color values should be between 0 and 255\n");
		return (0);
	}
	return (1);
}

int		check_beginning(char *str, int flag, char *arg, t_array *array)
{
	if (!(ft_check_isspace_beginning(array, str, arg)))
		return (-1);
	if (!(ft_after_map(array)))
		return (-1);
	if (!(ft_check_conflicting_arg(flag, arg)))
		return (-1);
	return (0);
}

int		ft_parser_floor(char **line, t_array *array)
{
	if (check_beginning(*line, array->floor, "Floor", array) == -1)
		return (-1);
	*line = move_isspace(*line);
	if (ft_isdigit(**line))
	{
		if (((*line = ft_atoi_digit_fc(*line, &array->f_r, "Floor")) == NULL)
				|| !(ft_correct_char(**line, ',', "Floor")))
			return (-1);
		(*line)++;
		if (((*line = ft_atoi_digit_fc(*line, &array->f_g, "Floor")) == NULL)
				|| !(ft_correct_char(**line, ',', "Floor")))
			return (-1);
		(*line)++;
		if ((*line = ft_atoi_digit_fc(*line, &array->f_b, "Floor")) == NULL)
			return (-1);
		*line = move_isspace(*line);
		if (!(check_nothing_more(**line, "Floor")))
			return (-1);
		if (!(ft_check_range_colors(array->f_r, array->f_g, array->f_b)))
			return (-1);
		array->floor = 1;
		return (0);
	}
	putstr_error_fc("Floor");
	return (-1);
}

int		ft_parser_ceiling(char **line, t_array *array)
{
	if (check_beginning(*line, array->ceiling, "Ceiling", array) == -1)
		return (-1);
	*line = move_isspace(*line);
	if (ft_isdigit(**line))
	{
		if (((*line = ft_atoi_digit_fc(*line, &array->c_r, "Ceiling")) == NULL)
				|| !(ft_correct_char(**line, ',', "Ceiling")))
			return (-1);
		(*line)++;
		if (((*line = ft_atoi_digit_fc(*line, &array->c_g, "Ceiling")) == NULL)
				|| !(ft_correct_char(**line, ',', "Ceiling")))
			return (-1);
		(*line)++;
		if ((*line = ft_atoi_digit_fc(*line, &array->c_b, "Ceiling")) == NULL)
			return (-1);
		*line = move_isspace(*line);
		if (!(check_nothing_more(**line, "Ceiling")))
			return (-1);
		if (!(ft_check_range_colors(array->c_r, array->c_g, array->c_b)))
			return (-1);
		array->ceiling = 1;
		return (0);
	}
	putstr_error_fc("Ceiling");
	return (-1);
}

int		parser_ceiling_floor_data(char **line, t_array *array)
{
	*line = move_isspace(*line);
	if (**line == 'F')
	{
		(*line)++;
		if (ft_parser_floor(line, array) == -1)
			return (-1);
		else
			return (1);
	}
	else if (**line == 'C')
	{
		(*line)++;
		if (ft_parser_ceiling(line, array) == -1)
			return (-1);
		else
			return (1);
	}
	else if (**line != '\0')
	{
		if (wrong_char(array, **line, *line))
			return (-1);
	}
	return (0);
}
