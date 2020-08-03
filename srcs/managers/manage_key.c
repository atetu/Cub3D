/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:58:45 by atetu             #+#    #+#             */
/*   Updated: 2020/02/24 16:47:29 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		key_pressed(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->is_forward_pressed = 1;
	if (keycode == KEY_S)
		player->is_backward_pressed = 1;
	if (keycode == KEY_A)
		player->is_move_left_pressed = 1;
	if (keycode == KEY_D)
		player->is_move_right_pressed = 1;
	if (keycode == LEFT)
		player->is_look_left_pressed = 1;
	if (keycode == RIGHT)
		player->is_look_right_pressed = 1;
	if (keycode == SHIFT)
		player->is_shift_pressed = 1;
	if (keycode == ESC)
		player->exit = 1;
	return (0);
}

int		key_released(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->is_forward_pressed = 0;
	if (keycode == KEY_S)
		player->is_backward_pressed = 0;
	if (keycode == KEY_A)
		player->is_move_left_pressed = 0;
	if (keycode == KEY_D)
		player->is_move_right_pressed = 0;
	if (keycode == LEFT)
		player->is_look_left_pressed = 0;
	if (keycode == RIGHT)
		player->is_look_right_pressed = 0;
	if (keycode == SHIFT)
		player->is_shift_pressed = 0;
	if (keycode == ESC)
		player->exit = 1;
	return (0);
}

void	move_pos(t_player *player, double *new_pos_x, double *new_pos_y)
{
	double	boost;

	boost = 1.0;
	if (player->is_shift_pressed)
		boost = 2.0;
	if (player->is_forward_pressed)
	{
		*new_pos_x += player->dir_x * 0.10 * boost;
		*new_pos_y += player->dir_y * 0.10 * boost;
	}
	if (player->is_backward_pressed)
	{
		*new_pos_x -= player->dir_x * 0.10 * boost;
		*new_pos_y -= player->dir_y * 0.10 * boost;
	}
	if (player->is_move_left_pressed)
	{
		*new_pos_x -= player->screen_x * 0.10 * boost;
		*new_pos_y -= player->screen_y * 0.10 * boost;
	}
	if (player->is_move_right_pressed)
	{
		*new_pos_x += player->screen_x * 0.10 * boost;
		*new_pos_y += player->screen_y * 0.10 * boost;
	}
}

int		key_hook(t_player *player)
{
	double new_pos_x;
	double new_pos_y;

	new_pos_x = player->pos_x;
	new_pos_y = player->pos_y;
	move_pos(player, &new_pos_x, &new_pos_y);
	if ((player->map[(int)player->pos_y][(int)new_pos_x] != '1' &&
				player->map[(int)player->pos_y][(int)new_pos_x] != '2'))
		player->pos_x = new_pos_x;
	if (player->map[(int)new_pos_y][(int)player->pos_x] != '1' &&
			player->map[(int)new_pos_y][(int)player->pos_x] != '2')
		player->pos_y = new_pos_y;
	return (0);
}
