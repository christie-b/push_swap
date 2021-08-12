/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:23:46 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 10:08:51 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	find_spot2(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_a->tab[0] > stack_b->tab[0] && stack_a->tab[0]
		< stack_b->tab[stack_b->size - 1])
		;
	else
	{
		while (stack_a->tab[0] > stack_b->tab[i])
			i++;
		while (stack_a->tab[0] < stack_b->tab[i])
			i++;
	}
	return (i);
}

int	find_spot1(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	if (stack_b->size > 0)
	{
		if (stack_a->tab[0] > get_max(stack_b, stack_b->size))
		{
			while (stack_b->tab[i] != get_max(stack_b, stack_b->size))
				i++;
		}
		else if (stack_a->tab[0] < get_min(stack_b, stack_b->size))
		{
			while (stack_b->tab[i] != get_min(stack_b, stack_b->size))
				i++;
			i++;
		}
		else
			i = find_spot2(stack_a, stack_b);
	}
	return (i);
}

void	set_spot(int i, t_stack *stack_a, t_stack *stack_b)
{
	if (i > stack_b->size / 2)
	{
		i = stack_b->size - i;
		while (i > 0)
		{
			ft_rev_rotate(stack_b, "rrb");
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_rotate(stack_b, "rb");
			i--;
		}
	}
	ft_push(stack_b, stack_a, "pb");
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_b->tab[i] != get_max(stack_b, stack_b->size))
		i++;
	if (i > stack_b->size / 2)
	{
		i = stack_b->size - i;
		while (i > 0)
		{
			ft_rev_rotate(stack_b, "rrb");
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_rotate(stack_b, "rb");
			i--;
		}
	}
	while (stack_b->size > 0)
		ft_push(stack_a, stack_b, "pa");
}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;
	int	max;

	min = 0;
	max = 15;
	while (max <= stack_a->capacity)
	{
		while (stack_b->size <= max)
		{
			move_hold_to_top(stack_a, min, max);
			i = find_spot1(stack_a, stack_b);
			set_spot(i, stack_a, stack_b);
		}
		if (max == -1)
			break ;
		min = set_min(stack_a, min);
		max = set_max(stack_a, max);
	}
	push_to_a(stack_a, stack_b);
}
