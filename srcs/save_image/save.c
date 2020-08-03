/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:58:33 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 14:40:31 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_initialize_header(t_header *header, t_player *player)
{
	header->size = 40;
	header->width = player->resolution_x;
	header->height = player->resolution_y;
	header->planes = 1;
	header->bpp = player->image->bpp;
	header->compression = 0;
	header->image_size = 0;
	header->hor_resolution = 0;
	header->vert_resolution = 0;
	header->nb_colors = 0;
	header->nb_imp_colors = 0;
}

void	write_header(int fd, t_player *player)
{
	t_header header;

	ft_initialize_header(&header, player);
	write(fd, &header.size, 4);
	write(fd, &header.width, 4);
	write(fd, &header.height, 4);
	write(fd, &header.planes, 2);
	write(fd, &header.bpp, 2);
	write(fd, &header.compression, 4);
	write(fd, &header.image_size, 4);
	write(fd, &header.hor_resolution, 4);
	write(fd, &header.vert_resolution, 4);
	write(fd, &header.nb_colors, 4);
	write(fd, &header.nb_imp_colors, 4);
}

void	write_data(int fd, t_player *player)
{
	int		i;
	int		j;
	char	*buffer;

	i = player->image->width * player->image->height;
	i = i - player->image->width;
	buffer = (char *)player->image->pic;
	while (i >= 0)
	{
		j = 0;
		while (j < player->image->width)
		{
			write(fd, &buffer[i * player->image->bpp / 8], 4);
			i++;
			j++;
		}
		i = i - (2 * player->image->width);
	}
}

int		write_bpm(int fd, t_player *player)
{
	int file_size;
	int reserved_field;
	int offset;
	int padding;

	padding = player->image->width % 4;
	file_size = 14 + 40 + (player->image->width * 4 * player->image->height);
	reserved_field = 0;
	offset = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, &reserved_field, 4);
	write(fd, &offset, 4);
	write_header(fd, player);
	write_data(fd, player);
	return (0);
}

int		ft_save(t_player *player)
{
	int		fd;
	char	*file;

	file = NULL;
	file = ft_strjoin("save_im", ".bmp");
	fd = open(file, O_WRONLY | O_CREAT, 0664);
	if (fd < 0)
	{
		ft_putstr("Error\n: Problem with the creation of the export file\n");
		ft_free_str(file);
		ft_exit_esc(player);
	}
	write_bpm(fd, player);
	if (close(fd) < 0)
		ft_putstr("Error\n: Problem with the closing of the export file\n");
	ft_free_str(file);
	ft_exit_esc_save(player);
	return (0);
}
