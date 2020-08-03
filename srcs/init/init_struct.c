/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:30:12 by atetu             #+#    #+#             */
/*   Updated: 2020/03/03 18:55:59 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_initialize_array(t_array *array)
{
	ft_memset(array, 0, sizeof(t_array));
}

int		ft_initialize_player(t_player *player, t_array *array, char **map)
{
	player->resolution_x = array->resolution_x;
	player->resolution_y = array->resolution_y;
	player->dir_x = 0.00;
	player->dir_y = 0.00;
	player->screen_x = 0.00;
	player->screen_y = 0.00;
	player->rot_speed = 0.09;
	player->pos_y = array->pos_y + 0.50;
	player->pos_x = array->pos_x + 0.50;
	player->map = map;
	player->first_loop = 0;
	player->color_ceiling = color_assemble(array->c_r, array->c_g, array->c_b);
	player->color_floor = color_assemble(array->f_r, array->f_g, array->f_b);
	player->count_sprites = array->count_sprites;
	player->array_sprite = array->array_sprite;
	player->exit = 0;
	player->rows = array->rows;
	player->save = array->save;
	player->ptr = NULL;
	player->win_ptr = NULL;
	player->image = NULL;
	return (1);
}

void	init_text_struct_player(t_player *player)
{
	player->tex_north = NULL;
	player->tex_south = NULL;
	player->tex_west = NULL;
	player->tex_east = NULL;
	player->sprite = NULL;
}
