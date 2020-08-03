/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 18:51:34 by atetu             #+#    #+#             */
/*   Updated: 2020/02/22 19:49:47 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		key_rotation(t_player *player)
{
	if (player->is_look_left_pressed)
		key_rotation_left(player);
	if (player->is_look_right_pressed)
		key_rotation_right(player);
	return (0);
}

void	key_rotation_left(t_player *player)
{
	double current_dir_x;
	double current_screen_x;

	current_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(-player->rot_speed) - player->dir_y *
		sin(-player->rot_speed);
	player->dir_y = current_dir_x * sin(-player->rot_speed) + player->dir_y
		* cos(-player->rot_speed);
	current_screen_x = player->screen_x;
	player->screen_x = player->screen_x * cos(-player->rot_speed) -
		player->screen_y * sin(-player->rot_speed);
	player->screen_y = current_screen_x * sin(-player->rot_speed) +
		player->screen_y * cos(-player->rot_speed);
}

void	key_rotation_right(t_player *player)
{
	double current_dir_x;
	double current_screen_x;

	current_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(player->rot_speed) - player->dir_y
		* sin(player->rot_speed);
	player->dir_y = current_dir_x * sin(player->rot_speed) + player->dir_y
		* cos(player->rot_speed);
	current_screen_x = player->screen_x;
	player->screen_x = player->screen_x * cos(player->rot_speed) -
		player->screen_y * sin(player->rot_speed);
	player->screen_y = current_screen_x * sin(player->rot_speed) +
		player->screen_y * cos(player->rot_speed);
}
