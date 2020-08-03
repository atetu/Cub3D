/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:41:10 by atetu             #+#    #+#             */
/*   Updated: 2019/11/13 17:45:21 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		len;
	int		count;

	count = 0;
	if (!s)
		return (0);
	len = ft_strlen(s) + 1;
	if (!(result = (char *)malloc(sizeof(char) * len)))
		return (0);
	while (s[count])
	{
		result[count] = (*f)(count, s[count]);
		count++;
	}
	result[count] = 0;
	return (result);
}
