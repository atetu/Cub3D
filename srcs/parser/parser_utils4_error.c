/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:40:51 by atetu             #+#    #+#             */
/*   Updated: 2020/03/07 13:46:44 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	error_wrong_configuration(void)
{
	ft_putstr("Error\n: Wrong configuration / Missing elements : ");
	ft_putstr("Resolution, ceiling, floor, sprite, and orientation ");
	ft_putstr("information should be given before the map.\n");
}

int		put_error(void)
{
	ft_putstr("Error\n: Wrong line in the file\n");
	return (1);
}

int		ft_after_map(t_array *array)
{
	if (array->flag_map)
	{
		ft_putstr("Error\n: No element after map\n");
		return (0);
	}
	return (1);
}

int		error_wrong_conf_wmap(char c, int i)
{
	if (c == '\0' && i != 1)
	{
		ft_putstr("Error\n: Wrong configuration of the file - ");
		ft_putstr("Map should only start with a '0', '1', '2' or a space ");
		ft_putstr("and resolution, ceiling, floor, orientation, sprite ");
		ft_putstr("information should be given before the map\n");
		return (1);
	}
	return (0);
}

void	error_wrong_line_configuration(char *arg)
{
	ft_putstr("Error\n: Wrong line in the file or ");
	ft_putstr("wrong configuration of the ");
	ft_putstr(arg);
	ft_putstr(" argument\n");
}
