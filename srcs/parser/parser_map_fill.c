/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_fill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 10:57:41 by atetu             #+#    #+#             */
/*   Updated: 2020/03/04 16:33:10 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		check_longest_line(char **map, t_array *array)
{
	int len;
	int y;

	len = 0;
	y = 0;
	while (y < array->rows)
	{
		if ((int)ft_strlen(map[y]) > len)
			len = ft_strlen(map[y]);
		y++;
	}
	array->len_line = len;
	return (len);
}

int		creation_new_row(char **new_map, int len, int **hit)
{
	*new_map = NULL;
	*hit = NULL;
	if (!(*new_map = malloc(sizeof(char*) * (len + 1))))
		return (0);
	if (!(*hit = malloc(sizeof(char*) * (len + 1))))
		return (0);
	*new_map[0] = 0;
	*hit[0] = 0;
	return (1);
}

int		ft_fill_new_map_row(char **new_map, char **map, int len, int **hit)
{
	int i;

	i = 0;
	if (!(creation_new_row(new_map, len, hit)))
		return (0);
	while ((*map)[i] != '\0')
	{
		(*new_map)[i] = (*map)[i];
		(*hit)[i] = 0;
		i++;
	}
	if (i < (len - 1))
	{
		while (i < len)
		{
			(*new_map)[i] = 'X';
			(*hit)[i] = 0;
			i++;
		}
	}
	(*new_map)[i] = '\0';
	(*hit)[i] = '\0';
	return (1);
}

int		creation_new_map(char ***new_map, int ***hit, t_array *array,
		char ***map)
{
	*new_map = NULL;
	*hit = NULL;
	if (!(*new_map = malloc(sizeof(char*) * (array->rows + 1))))
	{
		*map = ft_free_map(*map);
		return (0);
	}
	(*new_map)[0] = 0;
	if (!(*hit = malloc(sizeof(*hit) * (array->rows + 1))))
	{
		*map = ft_free_map(*map);
		*new_map = ft_free_map(*map);
		return (0);
	}
	(*hit)[0] = 0;
	return (1);
}

int		ft_fill_new_map(char **map, t_array *array, int len)
{
	char	**new_map;
	int		**hit;
	int		y;

	y = 0;
	if (!(map[0]))
		return (0);
	if (!(creation_new_map(&new_map, &hit, array, &map)))
		return (-1);
	while (y < array->rows)
	{
		if (!(ft_fill_new_map_row(&(new_map[y]), &(map[y]), len, &(hit[y]))))
		{
			array->hit = hit;
			ft_free_map_new_hit(&map, array, &new_map);
			return (-1);
		}
		y++;
	}
	new_map[y] = 0;
	hit[y] = 0;
	map = ft_free_map(map);
	array->map = new_map;
	array->hit = hit;
	return (1);
}
