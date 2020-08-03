/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:44:52 by atetu             #+#    #+#             */
/*   Updated: 2020/02/25 15:51:45 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	initialize_ray(t_player *player, t_ray *ray)
{
	ray->resolution_x = player->resolution_x;
	ray->resolution_y = player->resolution_y;
	ray->cursor = 0.0;
	ray->position_screen = 0.0;
	ray->wall_dist = 0.0;
	ray->x_start = 0;
	ray->ray_x = 0.0;
	ray->ray_y = 0.0;
	ray->tile_x = 0;
	ray->tile_y = 0;
	ray->first_dist_x = 0.0;
	ray->first_dist_y = 0.0;
	ray->dist_x = 0.0;
	ray->dist_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->wall_x = 0.0;
	ray->step = 0.0;
	ray->tex_x = 0;
	ray->tex_y = 0.0;
}

void	initialize_draw(t_draw *draw)
{
	draw->line_height = 0;
	draw->start_line = 0;
	draw->end_line = 0;
}

int		initialization_image(t_player *player)
{
	t_image	*image;

	if (!(image = malloc(sizeof(t_image))))
		return (0);
	image->width = player->resolution_x;
	image->height = player->resolution_y;
	image->img_ptr = mlx_new_image(player->ptr, image->width, image->height);
	if (!(image->pic = (int *)mlx_get_data_addr(image->img_ptr, &image->bpp,
			&image->stride, &image->endian)))
	{
		ft_putstr("Error\n: Problem with the creation of the image");
		ft_exit_esc(player);
	}
	image->line = image->stride / sizeof(int);
	player->image = image;
	return (1);
}

void	handle_exit(t_player *player)
{
	ft_putstr("Error\n: Problem of memory allocation\n");
	ft_exit_esc(player);
}
