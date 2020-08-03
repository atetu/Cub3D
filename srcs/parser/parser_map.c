/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:49:20 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 16:53:02 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		check_first_row(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(map_character(str[i])) && !(ft_isspace(str[i])))
		{
			ft_putstr("Error\n: Wrong configuration of the map\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_check_first_char(char **line, int i, int row)
{
	if ((*line)[i] != '1' && (*line)[i] != '2' && (*line)[i] != '0')
	{
		if (row > 0)
			ft_putstr("Error\n: Wrong configuration of the map\n");
		return (0);
	}
	return (1);
}

int		ft_check_all_char(char **line, int i)
{
	static int player = 0;

	while ((*line)[i] != '\0')
	{
		if ((*line)[i] != '0' && (*line)[i] != '1' && (*line)[i] != '2'
				&& (*line)[i] != 'N' && (*line)[i] != 'S'
				&& (*line)[i] != 'E' && (*line)[i] != 'W'
				&& !(ft_isspace((*line)[i])))
		{
			ft_putstr("Error\n: Wrong character in the map\n");
			return (-1);
		}
		if ((*line)[i] == 'N' || (*line)[i] == 'S'
				|| (*line)[i] == 'E' || (*line)[i] == 'W')
			player++;
		if (player > 1)
		{
			ft_putstr("Error\n: Too many players\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_check_row(char **line, int i, int row, int *end)
{
	if ((*line)[i] == '\0')
	{
		*end = 1;
		return (row);
	}
	else
	{
		if (*end == 1)
		{
			ft_putstr("Error\n: Wrong configuration of the map\n");
			return (-1);
		}
		if (!(ft_check_first_char(line, i, row)))
			return (-1);
		if (ft_check_all_char(line, i) == -1)
			return (-1);
		row++;
	}
	return (row);
}

int		parser_map(char **line, t_array *array)
{
	int			i;
	static int	row = 0;
	static int	end = 0;

	i = 0;
	while (ft_isspace((*line)[i]))
		i++;
	if (row == 0 && (ft_check_first_char(line, i, row)))
	{
		if (check_first_row(&(*line)[i]) == -1)
			return (-1);
		row++;
		array->flag_map = 1;
	}
	else if (wrong_line(row, (*line)[i]))
		return (-1);
	else if (row == 0 && (*line)[i] == '\0')
		return (0);
	else if (row)
	{
		if ((row = ft_check_row(line, i, row, &end)) == -1)
			return (-1);
	}
	array->height = row;
	return (row);
}
