/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:48:35 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:43:08 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		map_character(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W')
		return (1);
	return (0);
}

int		wrong_line(int row, char c)
{
	if (row == 0 && c != '\0' && c != 'R' && c != 'F' && c != 'E' && c != 'N'
			&& c != 'S' && c != 'W' && c != 'S' && c != 'C'
			&& !(ft_isspace(c)))
	{
		ft_putstr("Wrong line in the file\n");
		return (1);
	}
	return (0);
}

int		no_char_map(char **line, int *i)
{
	if ((*line)[*i] == '0' || (*line)[*i] == '1' || (*line)[*i] == '2'
				|| (*line)[*i] == 'N' || (*line)[*i] == 'S'
				|| (*line)[*i] == 'E' || (*line)[*i] == 'W'
				|| ft_isspace((*line)[*i]))
		(*i)++;
	else
	{
		ft_putstr("Error\n: Wrong character in the map\n");
		return (1);
	}
	return (0);
}

int		is_malloc_map(char **map, int nb)
{
	if (!(*map = malloc(sizeof(char) * (nb + 1))))
	{
		ft_putstr("Error\n: Problem during parsing");
		return (0);
	}
	return (1);
}
