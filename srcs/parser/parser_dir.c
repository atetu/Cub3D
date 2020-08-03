/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:53:35 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 12:59:28 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_parser_dir_no(char **line, t_array *array, char *data)
{
	int i;

	i = 0;
	if (**line == 'N')
	{
		i++;
		if (check_char_dir((*line)[i], 'O', data, 'N'))
			i++;
		else
		{
			error_wrong_line(line, array);
			return (-1);
		}
		if (!(ft_check_isspace_beginning(array, &((*line)[i]), "North")))
			return (-1);
		if (!(ft_after_map(array)))
			return (-1);
		if (!(ft_check_conflicting_arg_str(array->no, "North orientation")))
			return (-1);
		if ((ft_fill_array(line, i, &(array->no), "North")) == -1)
			return (-1);
	}
	return (0);
}

int		ft_check_conflicting_arg_south_sprites(char *data, t_array *array)
{
	if (!(ft_after_map(array)))
		return (0);
	if (*data == 'S' &&
			!(ft_check_conflicting_arg_str(array->so, "South orientation")))
		return (0);
	if (*data == 'P' && !(ft_check_conflicting_arg_str(array->sp, "Sprites")))
		return (0);
	return (1);
}

int		ft_parser_dir_so_p(char **line, t_array *array, char *data)
{
	int		i;

	i = 0;
	if (**line == 'S')
	{
		i++;
		if (check_char_dir((*line)[i], 'O', data, 'S'))
		{
			i++;
			if (!(ft_check_isspace_beginning(array, &((*line)[i]), "South")))
				return (-1);
		}
		else if (ft_isspace((*line)[i]))
			*data = 'P';
		else if ((*line)[i] == '\0' && !(ft_after_map(array)))
			return (-1);
		else if (!(ft_check_isspace_beginning(array, &((*line)[i]), "Sprite")))
			return (-1);
		else if (error_wrong_line(line, array))
			return (-1);
		if (!end_line_ok(data, array, line, i))
			return (-1);
	}
	return (0);
}

int		ft_parser_dir_we(char **line, t_array *array, char *data)
{
	int i;

	i = 0;
	if ((*line)[i] == 'W')
	{
		i++;
		if (check_char_dir((*line)[i], 'E', data, 'W'))
			i++;
		else
		{
			error_wrong_line(line, array);
			return (-1);
		}
		if (!(ft_check_isspace_beginning(array, &((*line)[i]), "West")))
			return (-1);
		if (!(ft_after_map(array)))
			return (-1);
		if (!(ft_check_conflicting_arg_str(array->we, "West orientation")))
			return (-1);
		if (ft_fill_array(line, i, &(array->we), "West") == -1)
			return (-1);
	}
	return (0);
}

int		ft_parser_dir_ea(char **line, t_array *array, char *data)
{
	int i;

	i = 0;
	if ((*line)[i] == 'E')
	{
		i++;
		if (check_char_dir((*line)[i], 'A', data, 'E'))
			i++;
		else
		{
			error_wrong_line(line, array);
			return (-1);
		}
		if (!(ft_check_isspace_beginning(array, &((*line)[i]), "East")))
			return (-1);
		if (!(ft_after_map(array)))
			return (-1);
		if (!(ft_check_conflicting_arg_str(array->ea, "East orientation")))
			return (-1);
		if (ft_fill_array(line, i, &(array->ea), "East") == -1)
			return (-1);
	}
	return (0);
}
