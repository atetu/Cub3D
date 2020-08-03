/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:38:14 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 14:49:23 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_check_result(int result)
{
	if (result < 0)
	{
		ft_putstr("Error\n: Problem during parsing\n");
		return (0);
	}
	return (1);
}

int		ft_first_read(char **argv, t_array *array, int *fd)
{
	char	*line;
	int		result;

	line = NULL;
	*fd = open(argv[1], O_RDONLY);
	if (ft_open(*fd) == -1)
		return (-1);
	while ((result = get_next_line(*fd, &line)) || 1)
	{
		if (((parse_line(&line, array)) == -1) || (!(ft_check_result(result))))
		{
			ft_free_str(line);
			ft_free_texture_array(array);
			return (-1);
		}
		if (result == 0)
		{
			ft_free_str(line);
			break ;
		}
	}
	if (ft_close(*fd) == -1)
		return (-1);
	return (array->rows);
}

int		ft_map(char **map, t_array *array)
{
	int res;

	if (map)
	{
		if (!(ft_pos(map, array)))
		{
			map = ft_free_map(map);
			array->hit = ft_free_hit(array);
			return (-1);
		}
		res = ft_check_map(map, array, (int)array->pos_x, (int)array->pos_y);
		if (res == 1)
		{
			ft_free_map_hit(&map, array);
			ft_putstr("Error\n : The map is not closed\n");
			return (-1);
		}
		if (ft_initialize_sprites(map, array) == -1)
		{
			ft_free_map_hit(&map, array);
			return (-1);
		}
	}
	array->hit = ft_free_hit(array);
	return (0);
}

char	**ft_second_read(char **argv, int rows, char **map, t_array *array)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Error\n");
		return (NULL);
	}
	if (!(map = malloc(sizeof(char*) * (rows + 1))))
		return (NULL);
	map[0] = 0;
	if (ft_transpose_file_to_map(fd, &line, map, array) == -1)
		return (NULL);
	if (ft_fill_new_map(map, array, check_longest_line(map, array)) == -1)
		return (NULL);
	map = array->map;
	if (ft_close(fd) == -1)
	{
		ft_free_map_hit(&map, array);
		return (NULL);
	}
	if (ft_map(map, array) == -1)
		return (NULL);
	return (map);
}

int		main(int argc, char **argv)
{
	int			rows;
	char		**map;
	int			fd;
	t_array		array;

	map = NULL;
	ft_initialize_array(&array);
	if (!(ft_check_nb_argc(argc, argv, &array)))
		return (-1);
	if ((rows = ft_first_read(argv, &array, &fd)) == -1)
		return (-1);
	if (!(ft_struct2_ok(&array)))
	{
		which_missing(&array);
		return (-1);
	}
	if (!(ft_resolution_ok(&array)))
	{
		ft_putstr("Error\n: Wrong resolution\n");
		return (-1);
	}
	if ((map = ft_second_read(argv, rows, map, &array)) == NULL)
		return (-1);
	window(&array, map);
	return (0);
}
