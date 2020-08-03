/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_load_tex_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 18:27:49 by atetu             #+#    #+#             */
/*   Updated: 2020/02/26 15:48:58 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		texture_info(t_player *player, t_loaded_image *tex, char *dir)
{
	if (!(tex->ptr = mlx_xpm_file_to_image(player->ptr, dir, &tex->width,
			&tex->height)))
	{
		ft_putstr("Error\n: Problem with loading of texture files\n");
		ft_free_map_player(player);
		if (player->ptr)
		{
			free(player->ptr);
			player->ptr = NULL;
			exit(1);
		}
	}
	tex->pic = (int *)mlx_get_data_addr(tex->ptr, &tex->bpp, &tex->stride,
			&tex->endian);
	tex->line = tex->stride / sizeof(int);
	return (0);
}

int		load_image(t_player *player, t_array *array)
{
	init_text_struct_player(player);
	if (!(player->tex_north = malloc(sizeof(t_loaded_image))))
		return (-1);
	if (!(player->tex_south = malloc(sizeof(t_loaded_image))))
		return (-1);
	if (!(player->tex_west = malloc(sizeof(t_loaded_image))))
		return (-1);
	if (!(player->tex_east = malloc(sizeof(t_loaded_image))))
		return (-1);
	if (!(player->sprite = malloc(sizeof(t_loaded_image))))
		return (-1);
	texture_info(player, player->tex_north, array->no);
	texture_info(player, player->tex_south, array->so);
	texture_info(player, player->tex_west, array->we);
	texture_info(player, player->tex_east, array->ea);
	texture_info(player, player->sprite, array->sp);
	return (0);
}
