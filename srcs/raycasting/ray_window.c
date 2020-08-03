/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:06:31 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 19:24:50 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		window(t_array *array, char **map)
{
	t_player	player;

	ft_memset(&player, 0, sizeof(t_player));
	if (!(ft_initialize_player(&player, array, map)))
	{
		ft_free_map(map);
		return (-1);
	}
	ft_dir_plane(array->dir, &player);
	player.ptr = mlx_init();
	load_image(&player, array);
	if (player.save == 1)
		loop(&player);
	if (!(player.win_ptr = mlx_new_window(player.ptr, array->resolution_x,
					array->resolution_y, "screen")))
		return (-1);
	mlx_hook(player.win_ptr, 2, 0, &key_pressed, &player);
	mlx_hook(player.win_ptr, 3, 0, &key_released, &player);
	mlx_hook(player.win_ptr, 17, 0, &ft_exit_red_cross, &player);
	mlx_loop_hook(player.ptr, &loop, &player);
	mlx_loop(player.ptr);
	return (0);
}

int		loop(t_player *player)
{
	double		*zbuffer;

	zbuffer = NULL;
	if (player->exit == 1)
		ft_exit_esc(player);
	if (!(zbuffer = malloc(sizeof(double) * (double)player->resolution_x)))
		handle_exit(player);
	if (player->first_loop == 0)
	{
		if (!(initialization_image(player)))
			handle_exit(player);
	}
	draw_window(player, zbuffer);
	ft_sprite(player, zbuffer);
	zbuffer = ft_free_array(zbuffer);
	if (player->save == 1)
		ft_save(player);
	else
		mlx_put_image_to_window(player->ptr, player->win_ptr,
				player->image->img_ptr, 0, 0);
	if (player->first_loop == 0)
		player->first_loop = 1;
	key_hook(player);
	key_rotation(player);
	return (0);
}

int		draw_window(t_player *player, double *zbuffer)
{
	char			**map;
	t_ray			ray;
	t_draw			draw;
	t_loaded_image	*texture;

	initialize_ray(player, &ray);
	initialize_draw(&draw);
	map = player->map;
	while (ray.cursor < ray.resolution_x)
	{
		ray_determine_ray_tile(player, &ray);
		ray_distance(&ray, player);
		ray_hit(player, &ray);
		ray_calculate_line(&ray, &draw, player);
		texture = determine_texture(player, &ray);
		ray_calculate_texture(&ray, &draw, player, texture);
		ray_draw_floor_ceiling(player, &ray, &draw);
		ray_draw_texture(player, &draw, &ray, texture);
		zbuffer[ray.x_start] = ray.wall_dist;
		ray.x_start++;
		ray.cursor++;
	}
	return (1);
}

void	ray_draw_floor_ceiling(t_player *player, t_ray *ray, t_draw *draw)
{
	int i;

	i = 0;
	while (draw->start_line != 0 && i != draw->start_line)
	{
		player->image->pic[(i * player->image->line) + ray->x_start] =
			player->color_ceiling;
		i++;
	}
	if (draw->end_line < 0)
		draw->end_line = player->resolution_y;
	i = draw->end_line;
	while (i != ray->resolution_y)
	{
		player->image->pic[(i * player->image->line) + ray->x_start] =
			player->color_floor;
		i++;
	}
}
