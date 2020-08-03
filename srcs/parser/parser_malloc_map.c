/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:30:29 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 15:40:27 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_check_beginning_map(char **line, int *i)
{
	while ((*line)[*i] != '\0' && ft_isspace((*line)[*i]))
		(*i)++;
	if ((*line)[*i] != '0' && (*line)[*i] != '1' && (*line)[*i] != '2')
		return (0);
	return (1);
}

int		ft_creation_map(char **map, char **line, t_array *array)
{
	int	i;
	int res;

	i = 0;
	if ((res = ft_check_beginning_map(line, &i)) == 0)
		return (0);
	if (res == -1)
		return (-1);
	while ((*line)[i] != '\0')
	{
		if (no_char_map(line, &i))
			return (-1);
	}
	if ((array->count_sprites = ft_malloc_map(line, i + 1, 0, map)) == -1)
		return (-1);
	array->map_created = 1;
	return (0);
}

int		check_char_map(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S' || c == 'E'
			|| c == 'W' || ft_isspace(c))
		return (1);
	return (0);
}

void	establish_char_map(char *map, int *x, char c, int *sprites)
{
	map[*x] = c;
	(*x)++;
	if (c == '2')
		(*sprites)++;
}

int		ft_malloc_map(char **line, int nb, int i, char **map)
{
	int			x;
	static int	sprites = 0;

	x = 0;
	i = 0;
	while (*map != 0)
		map++;
	if (!(is_malloc_map(map, nb)))
		return (-1);
	while ((*line)[i] != '\0')
	{
		if (ft_isspace((*line)[i]))
		{
			(*map)[x] = 'X';
			x++;
		}
		else if (check_char_map((*line)[i]))
			establish_char_map(*map, &x, (*line)[i], &sprites);
		i++;
	}
	(*map)[x] = '\0';
	map++;
	*map = 0;
	return (sprites);
}
