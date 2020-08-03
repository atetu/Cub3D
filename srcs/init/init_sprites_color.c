/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:43:39 by atetu             #+#    #+#             */
/*   Updated: 2020/02/20 18:45:32 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_initialize_sprites(char **map, t_array *array)
{
	int	j;
	int i;
	int index;

	index = 0;
	if (!(array->array_sprite = malloc(sizeof(t_sprite) *
					array->count_sprites)))
		return (-1);
	j = 1;
	while (map[j] != 0)
	{
		i = 0;
		while (map[j][i] != 0)
		{
			if (map[j][i] == '2')
			{
				array->array_sprite[index].x = i + 0.50;
				array->array_sprite[index].y = j + 0.50;
				index++;
			}
			i++;
		}
		j++;
	}
	return (0);
}

int		color_assemble(int red, int green, int blue)
{
	int		color;

	color = red;
	color = (color << 8) + green;
	color = (color << 8) + blue;
	return (color);
}
