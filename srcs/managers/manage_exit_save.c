/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:57:46 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 14:49:48 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_destroy_save(t_player *player)
{
	ft_free_map_player(player);
	ft_free_texture(player);
	if (player->image->img_ptr)
		mlx_destroy_image(player->ptr, player->image->img_ptr);
	if (player->image)
	{
		free(player->image);
		player->image = NULL;
	}
	if (player->ptr)
	{
		free(player->ptr);
		player->ptr = NULL;
	}
}

int		ft_exit_esc_save(t_player *player)
{
	ft_destroy(player);
	exit(0);
	return (0);
}
