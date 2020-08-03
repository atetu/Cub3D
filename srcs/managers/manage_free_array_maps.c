/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_free_array_maps.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:01:07 by atetu             #+#    #+#             */
/*   Updated: 2020/03/04 16:22:57 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_free_map_player(t_player *player)
{
	int i;

	i = 0;
	if (player->map)
	{
		while (i < player->rows)
		{
			ft_free_str(player->map[i]);
			i++;
		}
		free(player->map);
		player->map = NULL;
	}
}

char	**ft_free_map(char **map)
{
	int i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			ft_free_str(map[i]);
			i++;
		}
		free(map);
		map = NULL;
	}
	return (map);
}

double	*ft_free_array(double *array)
{
	if (array)
	{
		free(array);
		array = NULL;
	}
	return (array);
}

int		**ft_free_hit(t_array *array)
{
	int i;

	i = 0;
	if (array->hit)
	{
		while (array->hit[i])
		{
			array->hit[i] = ft_free_int(array->hit[i]);
			i++;
		}
		free(array->hit);
		array->hit = NULL;
	}
	return (array->hit);
}

void	ft_free_map_new_hit(char ***map, t_array *array, char ***new_map)
{
	*map = ft_free_map(*map);
	ft_free_hit(array);
	*new_map = ft_free_map(*new_map);
}
