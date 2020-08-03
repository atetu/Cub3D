/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:19:13 by atetu             #+#    #+#             */
/*   Updated: 2020/03/03 16:55:31 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		check_len(int len, int rows)
{
	if (rows < 3 || len < 3)
	{
		ft_putstr("Error\n: Wrong configuration of the map\n");
		return (-1);
	}
	return (0);
}

int		check_one(char *str)
{
	int nb;

	nb = 0;
	while (*str)
	{
		if (*str != '1' && (!(ft_isspace(*str))))
		{
			ft_putstr("Error\n: Wrong configuration of the map\n");
			return (-1);
		}
		if (*str == '1')
			nb++;
		str++;
	}
	if (nb == 0)
	{
		ft_putstr("Error\n: Wrong configuration of the map\n");
		return (-1);
	}
	return (0);
}

int		check_one_char(char c)
{
	if (c != '1')
	{
		ft_putstr("Error\n: Wrong configuration of the map\n");
		return (-1);
	}
	return (0);
}

int		check_char(char *str, int len, int *position)
{
	int i;

	i = 1;
	while (i < (len - 1))
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
				&& str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'E' && str[i] != 'W')
		{
			ft_putstr("Error\n: Wrong configuration of the map\n");
			return (-1);
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			if (*position != 0)
			{
				ft_putstr("Error\n: Wrong configuration of the map\n");
				return (-1);
			}
			else
				*position = 1;
		}
		i++;
	}
	return (0);
}

int		ft_check_map(char **map, int rows, int j, t_array *array)
{
	int			len;
	static int	position = 0;

	if (check_one(map[0]) == -1 || check_one(map[rows - 1]) == -1)
		return (-1);
	len = ft_strlen(map[0]);
	if (check_len(len, rows) == -1)
		return (-1);
	while (map[j] != 0)
	{
		if ((int)ft_strlen(map[j]) != len)
		{
			ft_putstr("Error\n: Wrong configuration of the map\n");
			return (-1);
		}
		if (check_one_char(map[j][0]) == -1 ||
				check_one_char(map[j][len - 1]) == -1)
			return (-1);
		if (check_char(map[j], len, &position) == -1)
			return (-1);
		j++;
	}
	array->width = len;
	return (0);
}
