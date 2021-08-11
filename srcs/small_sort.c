/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:18:25 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/07 16:15:28 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->tab[0] > stack->tab[1])
		ft_swap(stack->tab, "sa");
}

void	sort_three(t_stack *stack)
{
	int	*tmp;

	tmp = stack->tab;
	if (tmp[0] > tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		ft_swap(tmp, "sa");
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
	{
		ft_swap(tmp, "sa");
		ft_rev_rotate(stack, "rra");
	}
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] < tmp[2])
		ft_rotate(stack, "ra");
	else if (tmp[0] < tmp[1] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
	{
		ft_swap(tmp, "sa");
		ft_rotate(stack, "ra");
	}
	else if (tmp[0] < tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
		ft_rev_rotate(stack, "rra");
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	sort_four_rotate(stack_a, stack_b);
	if (!(is_sorted(stack_a)))
	{
		sort_three(stack_a);
		ft_push(stack_a, stack_b, "pa");
	}
	while (stack_b->size)
		ft_push(stack_a, stack_b, "pa");
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min;

	min = get_min(stack_a, stack_a->size);
	sort_five_rotate(stack_a, stack_b, min);
	if (!(is_sorted(stack_a)))
	{
		sort_four(stack_a, stack_b);
		ft_push(stack_a, stack_b, "pa");
	}
}

void	sort_fiftyfive(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		min;
	int		index;
	int		k;

	k = stack_a->size;
	while (k > 3)
	{
		i = -1;
		min = INT_MAX;
		while (++i < stack_a->size)
		{
			if (stack_a->tab[i] < min)
			{
				min = stack_a->tab[i];
				index = i;
			}
		}
		sort_fiftyfive_rotate(stack_a, stack_a->size / 2, index);
		ft_push(stack_b, stack_a, "pb");
		k--;
	}
	sort_three(stack_a);
	while (stack_b->size)
		ft_push(stack_a, stack_b, "pa");
}
