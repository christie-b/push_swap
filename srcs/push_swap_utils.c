/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 10:56:45 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 13:04:25 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	put_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst > src)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}

long long	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
