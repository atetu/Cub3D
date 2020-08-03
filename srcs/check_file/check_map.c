/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:56:02 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 15:39:36 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_check_map(char **map, t_array *array, int x, int y)
{
	if (x < 0 || y < 0 || y > (array->rows - 1) || x > array->len_line
			|| map[y][x] == 'X')
		return (1);
	if (array->hit[y][x] == 1)
		return (0);
	else
		array->hit[y][x] = 1;
	if (map[y][x] == '1')
		return (0);
	return (ft_check_map(map, array, x, y - 1)
			|| ft_check_map(map, array, x + 1, y)
			|| ft_check_map(map, array, x, y + 1)
			|| ft_check_map(map, array, x - 1, y));
}
