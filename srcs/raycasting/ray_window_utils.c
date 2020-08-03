/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 18:04:07 by atetu             #+#    #+#             */
/*   Updated: 2020/02/24 15:26:39 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ray_determine_ray_tile(t_player *player, t_ray *ray)
{
	ray->position_screen = 2 * ray->cursor / ray->resolution_x - 1;
	ray->ray_x = player->dir_x + player->screen_x * ray->position_screen;
	ray->ray_y = player->dir_y + player->screen_y * ray->position_screen;
	ray->tile_x = (int)player->pos_x;
	ray->tile_y = (int)player->pos_y;
	ray->dist_x = fabs(1 / ray->ray_x);
	ray->dist_y = fabs(1 / ray->ray_y);
}

void	ray_distance(t_ray *ray, t_player *player)
{
	if (ray->ray_x < 0)
	{
		ray->step_x = -1;
		ray->first_dist_x = (player->pos_x - ray->tile_x)
			* ray->dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->first_dist_x = (ray->tile_x + 1.0 - player->pos_x)
			* ray->dist_x;
	}
	if (ray->ray_y < 0)
	{
		ray->step_y = -1;
		ray->first_dist_y = (player->pos_y - ray->tile_y)
			* ray->dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->first_dist_y = (ray->tile_y + 1.0 - player->pos_y)
			* ray->dist_y;
	}
}

void	ray_hit(t_player *player, t_ray *ray)
{
	int		hit;
	char	**map;

	map = player->map;
	hit = 0;
	while (hit == 0)
	{
		if (ray->first_dist_x < ray->first_dist_y)
		{
			ray->first_dist_x += ray->dist_x;
			ray->tile_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->first_dist_y += ray->dist_y;
			ray->tile_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->tile_y][ray->tile_x] == '1')
			hit = 1;
	}
	return ;
}

void	ray_calculate_line(t_ray *ray, t_draw *draw, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->tile_x - player->pos_x + (1 - ray->step_x)
				/ 2) / ray->ray_x;
	else
		ray->wall_dist = (ray->tile_y - player->pos_y + (1 - ray->step_y)
				/ 2) / ray->ray_y;
	if (ray->wall_dist != 0.0)
		draw->line_height = (int)(ray->resolution_y / ray->wall_dist);
	draw->start_line = -draw->line_height / 2 + ray->resolution_y / 2;
	if (draw->start_line < 0)
		draw->start_line = 0;
	draw->end_line = draw->line_height / 2 + ray->resolution_y / 2;
	if (draw->end_line >= ray->resolution_y)
		draw->end_line = ray->resolution_y - 1;
}

void	ray_calculate_texture(t_ray *ray, t_draw *draw, t_player *player,
		t_loaded_image *texture)
{
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->ray_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->ray_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_x > 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	if (ray->side == 1 && ray->ray_y < 0)
		ray->tex_x = texture->width - ray->tex_x - 1;
	ray->step = 1.0 * (double)texture->height / (double)draw->line_height;
	ray->tex_y = (draw->start_line - ray->resolution_y / 2 + draw->line_height
			/ 2) * ray->step;
}
