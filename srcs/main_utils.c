/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:16:05 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:45:09 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int		ft_open(int fd)
{
	if (fd == -1)
	{
		perror("Error\n");
		return (-1);
	}
	return (0);
}

int		ft_close(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error\n");
		return (-1);
	}
	return (0);
}

int		ft_check_nb_argc(int argc, char **argv, t_array *array)
{
	int	len;

	if (argc > 3)
	{
		ft_putstr("Error\n: Wrong number of arguments\n");
		return (0);
	}
	if (argc > 2)
		if (!(ft_check_save(argv, array)))
			return (0);
	if (argc == 1)
	{
		ft_putstr("Error\n: No map file\n");
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(&argv[1][len - 4], ".cub", 4) != 0)
	{
		ft_putstr("Error\n: No cub file in argument\n");
		return (0);
	}
	return (1);
}

int		parse_line(char **line, t_array *array)
{
	int res;

	if ((res = parser(line, array)) == -1)
		return (-1);
	if (res == 0 && ft_struct_ok(array))
	{
		if (array->wrong_line > 0)
		{
			ft_putstr("Error\n: Wrong line in the file\n");
			return (-1);
		}
		if ((array->rows = parser_map(line, array)) == -1)
			return (-1);
	}
	*line = ft_free_str(*line);
	return (0);
}

int		ft_transpose_file_to_map(int fd, char **line, char **map,
		t_array *array)
{
	int ret;

	ret = 0;
	while ((ret = get_next_line(fd, line)) || 1)
	{
		if (ft_creation_map(map, line, array) == -1)
		{
			map = ft_free_map(map);
			*line = ft_free_str(*line);
			return (-1);
		}
		*line = ft_free_str(*line);
		if (ret < 0)
		{
			ft_putstr("Error\n: Error during parsing");
			map = ft_free_map(map);
			return (-1);
		}
		if (ret == 0)
			break ;
	}
	return (0);
}
