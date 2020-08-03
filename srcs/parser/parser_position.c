/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:36:06 by atetu             #+#    #+#             */
/*   Updated: 2020/03/03 20:34:29 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_pos(char **map, t_array *array)
{
	int i;
	int j;

	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\0')
		{
			if (map[j][i] == 'N' || map[j][i] == 'S' || map[j][i] == 'E' ||
					map[j][i] == 'W')
			{
				array->pos_y = j;
				array->pos_x = i;
				array->dir = map[j][i];
				return (1);
			}
			else
				i++;
		}
		j++;
	}
	ft_putstr("Error\n: No player\n");
	return (0);
}
