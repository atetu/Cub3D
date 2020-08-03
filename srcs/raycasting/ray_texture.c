/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:25:13 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 17:42:22 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_loaded_image		*determine_texture(t_player *player, t_ray *ray)
{
	if (ray->side == 1)
	{
		if (ray->ray_y < 0)
			return (player->tex_north);
		else
			return (player->tex_south);
	}
	if (ray->side == 0)
	{
		if (ray->ray_x < 0)
			return (player->tex_west);
		else
			return (player->tex_east);
	}
	return (NULL);
}

void				ray_draw_texture_line(t_player *player, t_draw *draw,
		t_ray *ray, t_loaded_image *texture)
{
	int		i_tex;
	int		i_img;

	i_tex = ((int)ray->tex_y) * texture->line - ray->tex_x;
	i_img = draw->start_line * player->image->line + ray->x_start;
	if (i_tex < 0)
		i_tex = 0;
	if (i_tex >= texture->width * texture->height)
		i_tex = (texture->width * texture->height) - 1;
	player->image->pic[i_img] = texture->pic[i_tex];
	ray->tex_y += ray->step;
	draw->start_line++;
}

void				ray_draw_texture(t_player *player, t_draw *draw, t_ray *ray,
		t_loaded_image *texture)
{
	if (draw->end_line == player->resolution_y)
	{
		while (draw->start_line < draw->end_line)
			ray_draw_texture_line(player, draw, ray, texture);
	}
	else
	{
		while (draw->start_line <= draw->end_line)
			ray_draw_texture_line(player, draw, ray, texture);
	}
}
