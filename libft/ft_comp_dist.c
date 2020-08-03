/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:51:21 by atetu             #+#    #+#             */
/*   Updated: 2020/02/20 15:46:34 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_comp_dist(int *sprite_order, double *sprite_distance, int count)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < (count - 1))
	{
		j = i + 1;
		while (j < count)
		{
			if (sprite_distance[i] < sprite_distance[j])
			{
				tmp = sprite_distance[i];
				sprite_distance[i] = sprite_distance[j];
				sprite_distance[j] = tmp;
				tmp = sprite_order[i];
				sprite_order[i] = sprite_order[j];
				sprite_order[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
