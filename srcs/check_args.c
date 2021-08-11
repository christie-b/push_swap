/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:53:32 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/09 10:05:24 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	has_dup(t_stack *stack)
{
	int	i;
	int	j;
	int	dup;

	i = 0;
	dup = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->tab[i] == stack->tab[j])
			{
				dup++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (dup);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
		exit(1);
	else if (ac == 2 && !(*av[1]))
		put_error();
	else
	{
		while (i < ac)
		{
			if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
				put_error();
			j = 0;
			while (av[i][j])
			{
				if (!(ft_isdigit(ac, av)))
					put_error();
				j++;
			}
			i++;
		}
	}
}
