/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:45:37 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 12:08:45 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"
#include "../incl/push_swap.h"

char	*ft_free(char *ret_value, char *ptr1, char *ptr2)
{
	if (ptr1)
	{
		free(ptr1);
		ptr1 = NULL;
	}
	if (ptr2)
	{
		free(ptr2);
		ptr2 = NULL;
	}
	return (ret_value);
}

void	check_malloc(char *str)
{
	if (!str)
		free(str);
}

void	join_str(char **tmp, char **str, char *buf)
{
	*tmp = *str;
	*str = ft_strjoin(*str, buf);
	check_malloc(*str);
	free(*tmp);
}

char	*read_line(int fd, char *str)
{
	char	*buf;
	char	*tmp;
	int		ret;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf || fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(NULL, buf, NULL));
	if (!str)
	{
		str = ft_strdup("");
		check_malloc(str);
	}
	while (!(ft_strchr(str, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (ft_free(NULL, buf, NULL));
		buf[ret] = '\0';
		join_str(&tmp, &str, buf);
		if (ret == 0)
			break ;
	}
	return (ft_free(str, buf, NULL));
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*index;
	char		*tmp;

	if (read(fd, NULL, 0) == -1)
		return (-1);
	str = read_line(fd, str);
	if (fd < 0 || !line || !str)
		return (-1);
	index = ft_strchr(str, '\n');
	if (index > 0)
	{
		tmp = str;
		*line = ft_substr(str, 0, index - str);
		str = ft_substr(str, (index - str) + 1, ft_strlen(str));
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
}
