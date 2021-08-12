/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:28:33 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 13:18:58 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	get_min(t_stack *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < size)
	{
		if (stack->tab[i] < min)
			min = stack->tab[i];
		i++;
	}
	return (min);
}

int	get_max(t_stack *stack, int size)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < size)
	{
		if (stack->tab[i] > max)
			max = stack->tab[i];
		i++;
	}
	return (max);
}

int	ft_isdigit2(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if ((av[1][i] >= '0' && av[1][i] <= '9') || av[1][i] == '-'
			|| av[1][i] == '+' || av[1][i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_isdigit(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 2)
		return (ft_isdigit2(av));
	else
	{
		i = 0;
		while (++i < ac)
		{
			j = 0;
			while (av[i][j])
			{
				while (av[i][j] == '+' || av[i][j] == '-')
					j++;
				if (!(av[i][j] >= '0' && av[i][j] <= '9'))
					return (0);
				if ((av[i][j] >= '0' && av[i][j] <= '9'))
					j++;
				else
					return (0);
			}
		}
	}
	return (1);
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_is_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		else
			break;
	}
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
