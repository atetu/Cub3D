/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:37:45 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 12:19:03 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_fill_array(char **line, int i, char **str, char *arg)
{
	int j;
	int x;

	x = 0;
	while (ft_isspace((*line)[i]))
		i++;
	j = i;
	while ((*line)[j] && !(ft_isspace((*line)[j])))
		j++;
	*str = ft_substr_index(*line, i, j);
	while (x != (j))
	{
		(*line)++;
		x++;
	}
	*line = move_isspace(*line);
	if (!(check_nothing_more(**line, arg)))
		return (-1);
	return (0);
}

int		ft_fill_south_sprite(char *data, t_array *array, char **line, int i)
{
	if (*data == 'S')
	{
		if (array->so != 0)
		{
			ft_putstr("Error\n: Conflicting arguments - South orientation\n");
			return (-1);
		}
		if ((ft_fill_array(line, i, &(array->so), "South")) == -1)
			return (-1);
	}
	if (*data == 'P')
	{
		if (array->sp != 0)
		{
			ft_putstr("Error\n: Conflicting arguments - Sprites\n");
			return (-1);
		}
		if ((ft_fill_array(line, i, &(array->sp), "Sprites")) == -1)
			return (-1);
	}
	return (0);
}
