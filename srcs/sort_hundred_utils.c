/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:51:32 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 10:08:31 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	set_min(t_stack *stack_a, int min)
{
	if (stack_a->size >= 16)
		min += 16;
	else
		min += stack_a->capacity % 16;
	return (min);
}

int	set_max(t_stack *stack_a, int max)
{
	if (stack_a->size >= 16)
		max += 16;
	else
	{
		if (stack_a->capacity % 16 == 0)
			return (-1);
		else
			max += stack_a->capacity % 16;
	}
	return (max);
}

int	hold_first(t_stack *stack_a, int min, int max)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] >= min && stack_a->tab[i] <= max)
			return (i);
		else
			i++;
	}
	return (-1);
}

int	hold_second(t_stack *stack_a, int min, int max)
{
	int	i;

	i = stack_a->size - 1;
	while (i >= 0)
	{
		if (stack_a->tab[i] >= min && stack_a->tab[i] <= max)
			return (i);
		else
			i--;
	}
	return (-1);
}

void	move_hold_to_top(t_stack *stack_a, int min, int max)
{
	int	i;
	int	j;

	i = hold_first(stack_a, min, max);
	j = hold_second(stack_a, min, max);
	if (i <= stack_a->size / 2)
	{
		while (i)
		{
			ft_rotate(stack_a, "ra");
			i--;
		}
	}
	else
	{
		while (j <= stack_a->size)
		{
			ft_rev_rotate(stack_a, "rra");
			j++;
		}
	}
}
