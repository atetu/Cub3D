/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:45:59 by atetu             #+#    #+#             */
/*   Updated: 2020/03/06 13:28:58 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int		ft_struct_ok(t_array *array)
{
	if (array->no != NULL && array->so != NULL
			&& array->sp != NULL && array->we != NULL
			&& array->ea != NULL && array->floor == 1
			&& array->ceiling == 1 && array->resolution == 1)
		return (1);
	return (0);
}

int		ft_struct2_ok(t_array *array)
{
	if (array->no != NULL && array->so != NULL
			&& array->sp != NULL && array->we != NULL
			&& array->ea != NULL && array->floor == 1
			&& array->ceiling == 1 && array->resolution == 1
			&& array->flag_map == 1)
		return (1);
	return (0);
}

int		ft_resolution_ok(t_array *array)
{
	if (array->resolution_x <= 0 || array->resolution_y <= 0)
		return (0);
	if (array->resolution_x > 2560)
		array->resolution_x = 2560;
	if (array->resolution_y > 1440)
		array->resolution_y = 1440;
	return (1);
}

int		ft_check_save(char **argv, t_array *array)
{
	int i;

	i = 0;
	if (((int)ft_strlen(argv[2]) == 6) && (ft_strncmp(argv[2], "--save", 6)
				== 0))
		array->save = 1;
	else
	{
		ft_putstr("Error\n: Invalid second argument\n");
		return (0);
	}
	return (1);
}
