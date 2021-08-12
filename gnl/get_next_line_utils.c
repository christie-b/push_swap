/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 13:39:00 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 12:11:08 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/get_next_line.h"
#include "../incl/push_swap.h"

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((char)c == str[i])
		{
			return ((char *)(str + i));
		}
		i++;
	}
	if (c == 0)
		return ((char *)(str + i));
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	dst = malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	if (len > slen - start)
		len = slen - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
