/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:04:51 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 11:17:47 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_free_texture(t_player *player)
{
	if (player->tex_north)
		free(player->tex_north);
	if (player->tex_south)
		free(player->tex_south);
	if (player->tex_west)
		free(player->tex_west);
	if (player->tex_east)
		free(player->tex_east);
	if (player->sprite)
		free(player->sprite);
	player->tex_north = NULL;
	player->tex_south = NULL;
	player->tex_west = NULL;
	player->tex_east = NULL;
	player->sprite = NULL;
}

void	ft_free_texture_array(t_array *array)
{
	if (array->no)
		free(array->no);
	if (array->so)
		free(array->so);
	if (array->we)
		free(array->we);
	if (array->ea)
		free(array->ea);
	if (array->sp)
		free(array->sp);
	array->no = NULL;
	array->so = NULL;
	array->we = NULL;
	array->ea = NULL;
	array->sp = NULL;
}

char	*ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (str);
}

int		*ft_free_int(int *i)
{
	if (i)
	{
		free(i);
		i = NULL;
	}
	return (i);
}
