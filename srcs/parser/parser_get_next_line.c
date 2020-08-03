/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atetu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:58:37 by atetu             #+#    #+#             */
/*   Updated: 2020/02/24 19:23:33 by atetu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_free(char *s2)
{
	if (s2 != NULL)
	{
		free(s2);
		s2 = NULL;
	}
	return (s2);
}

int		ft_check_str(char **s1, char **l1)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*s1)[i] != '\n' && (*s1)[i] != '\0')
		i++;
	if (!(tmp = ft_strjoin2(*l1, *s1, i)))
		return (-1);
	*l1 = ft_free(*l1);
	*l1 = tmp;
	if ((*s1)[i] == '\n')
	{
		if (!(tmp = ft_substr(*s1, i + 1, 500 + 1)))
			return (-1);
		*s1 = ft_free(*s1);
		*s1 = tmp;
		return (1);
	}
	if ((*s1)[i] == '\0')
	{
		*s1 = ft_free(*s1);
		if (!(*s1 = ft_calloc(500 + 1, sizeof(char))))
			return (-1);
	}
	return (0);
}

int		ft_copy_line_substr(char ***s4, char ***l4)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((**s4)[i] != '\n' && (**s4)[i] != '\0')
		i++;
	if (!(tmp = ft_strjoin2(**l4, **s4, i)))
		return (-1);
	**l4 = ft_free(**l4);
	**l4 = tmp;
	if ((**s4)[i] == '\n')
	{
		if (!(tmp = ft_substr(**s4, i + 1, 500 + 1)))
			return (-1);
		**s4 = ft_free(**s4);
		**s4 = tmp;
		return (1);
	}
	return (0);
}

int		ft_read(char **s3, char **l3, int fd3, char *buf)
{
	int		ret;
	int		result;

	while (1)
	{
		if (!(buf = (char *)malloc(sizeof(char) * (500 + 1))))
			return (-1);
		if ((ret = read(fd3, buf, 500)) == -1)
			return (-1);
		if (ret == 0)
		{
			*s3 = ft_free(*s3);
			buf = ft_free(buf);
			return (0);
		}
		buf[ret] = '\0';
		ft_strlcpy(*s3, buf, ret + 1);
		buf = ft_free(buf);
		result = ft_copy_line_substr(&s3, &l3);
		if (result == -1)
			return (-1);
		if (result == 1)
			return (1);
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*str = NULL;
	int				result;
	char			*b;

	b = NULL;
	if (fd < 0 || line == NULL ||
		!(*line = ft_calloc(1, sizeof(char))))
		return (-1);
	if (str)
	{
		result = ft_check_str(&str, line);
		if (result == -1)
			return (-1);
		if (result == 1)
			return (1);
	}
	else if (!str)
		if (!(str = ft_calloc(500 + 1, sizeof(char))))
			return (-1);
	result = ft_read(&str, line, fd, b);
	if (result == 0)
		return (0);
	else if (result == 1)
		return (1);
	return (-1);
}
