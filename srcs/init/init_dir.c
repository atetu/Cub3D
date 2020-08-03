/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:54:29 by atetu             #+#    #+#             */
/*   Updated: 2020/02/25 13:55:55 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_dir_plane_ns(char dir, t_player *player)
{
	if (dir == 'N')
	{
		player->dir_x = 0.00;
		player->dir_y = -1.00;
		player->screen_x = 0.66;
		player->screen_y = 0.00;
	}
	if (dir == 'S')
	{
		player->dir_x = 0.00;
		player->dir_y = 1.00;
		player->screen_x = -0.66;
		player->screen_y = 0.00;
	}
}

void	ft_dir_plane_ew(char dir, t_player *player)
{
	if (dir == 'E')
	{
		player->dir_x = 1.00;
		player->dir_y = 0.00;
		player->screen_x = 0.00;
		player->screen_y = 0.66;
	}
	if (dir == 'W')
	{
		player->dir_x = -1.00;
		player->dir_y = 0.00;
		player->screen_x = 0.00;
		player->screen_y = -0.66;
	}
}

void	ft_dir_plane(char dir, t_player *player)
{
	ft_dir_plane_ns(dir, player);
	ft_dir_plane_ew(dir, player);
}
