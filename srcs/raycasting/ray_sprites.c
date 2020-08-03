/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 16:04:33 by atetu             #+#    #+#             */
/*   Updated: 2020/02/25 14:15:10 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	sort_sprites(t_player *player, int *sprite_order,
		double *sprite_distance)
{
	int i;

	i = 0;
	while (i < player->count_sprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((player->pos_x - player->array_sprite[i].x) *
				(player->pos_x - player->array_sprite[i].x) +
				(player->pos_y - player->array_sprite[i].y) *
				(player->pos_y - player->array_sprite[i].y));
		i++;
	}
	ft_comp_dist(sprite_order, sprite_distance, player->count_sprites);
}

void	calculate_sprites_height(t_sp *sp, t_player *player,
		int *sprite_order, int j)
{
	sp->sprite_x = player->array_sprite[sprite_order[j]].x - player->pos_x;
	sp->sprite_y = player->array_sprite[sprite_order[j]].y - player->pos_y;
	sp->inv = 1.0 / (player->screen_x * player->dir_y - player->dir_x *
			player->screen_y);
	sp->transform_x = sp->inv * (player->dir_y * sp->sprite_x - player->dir_x *
			sp->sprite_y);
	sp->transform_y = sp->inv * (-player->screen_y * sp->sprite_x +
			player->screen_x * sp->sprite_y);
	sp->sprite_screen_x = (int)((player->resolution_x / 2) * (1 +
				sp->transform_x / sp->transform_y));
	sp->sprite_height = abs((int)(player->resolution_y /
				(sp->transform_y))) / 1;
	sp->draw_start_y = -sp->sprite_height / 2 + player->resolution_y / 2 +
		((int)(0.0 / sp->transform_y));
	if (sp->draw_start_y < 0)
		sp->draw_start_y = 0;
	sp->draw_end_y = sp->sprite_height / 2 + player->resolution_y / 2 +
		((int)(0.0 / sp->transform_y));
	if (sp->draw_end_y >= player->resolution_y)
		sp->draw_end_y = player->resolution_y - 1;
}

void	calculate_sprites_width(t_sp *sp, t_player *player)
{
	sp->sprite_width = abs((int)(player->resolution_y /
				(sp->transform_y))) / 1;
	sp->draw_start_x = -sp->sprite_width / 2 + sp->sprite_screen_x;
	if (sp->draw_start_x < 0)
		sp->draw_start_x = 0;
	sp->draw_end_x = sp->sprite_width / 2 + sp->sprite_screen_x;
	if (sp->draw_end_x >= player->resolution_x)
		sp->draw_end_x = player->resolution_x - 1;
	sp->stripe = sp->draw_start_x;
}

void	draw_sprite(t_sp *sp, t_player *player, double *zbuffer)
{
	int y;
	int d;
	int e;

	sp->tex_x = (int)(256 * (sp->stripe - (-sp->sprite_width / 2 +
					sp->sprite_screen_x)) * player->sprite->width /
			sp->sprite_width) / 256;
	if (sp->transform_y > 0 && sp->stripe > 0 && sp->stripe <
			player->resolution_x && sp->transform_y < zbuffer[sp->stripe])
	{
		y = sp->draw_start_y;
		while (y < sp->draw_end_y)
		{
			d = (y - ((int)0.0 / sp->transform_y)) * 256 -
				player->resolution_y * 128 + sp->sprite_height * 128;
			sp->tex_y = ((d * player->sprite->height) / sp->sprite_height) /
				256;
			e = player->sprite->pic[player->sprite->width * sp->tex_y +
				sp->tex_x];
			if ((e & 0X00FFFFFF) != 0)
				player->image->pic[(y * player->image->line) +
					(sp->stripe)] = e;
			y += 1;
		}
	}
}

int		ft_sprite(t_player *player, double *zbuffer)
{
	int		sprite_order[player->count_sprites];
	double	sprite_distance[player->count_sprites];
	int		j;
	t_sp	sp;

	sort_sprites(player, sprite_order, sprite_distance);
	j = 0;
	while (j < player->count_sprites)
	{
		calculate_sprites_height(&sp, player, sprite_order, j);
		calculate_sprites_width(&sp, player);
		while (sp.stripe < sp.draw_end_x)
		{
			draw_sprite(&sp, player, zbuffer);
			sp.stripe += 1;
		}
		j += 1;
	}
	return (0);
}
