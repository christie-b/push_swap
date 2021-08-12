/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:19:08 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 10:06:23 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sort_four_rotate(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		if (stack_a->tab[i] == get_min(stack_a, stack_a->size))
		{
			while (i)
			{
				if (i == 3)
				{
					ft_rev_rotate(stack_a, "rra");
					break ;
				}
				else
				{
					ft_rotate(stack_a, "ra");
					i--;
				}
			}
			if (!(is_sorted(stack_a)))
				ft_push(stack_b, stack_a, "pb");
		}
		i++;
	}
}

void	sort_five_rotate(t_stack *stack_a, int i)
{
	while (i > 0)
	{
		if (i <= 2)
		{
			ft_rotate(stack_a, "ra");
			i--;
		}
		else
		{
			i = stack_a->size - i;
			while (i > 0)
			{
				ft_rev_rotate(stack_a, "rra");
				i--;
			}
		}
	}
}

void	sort_twenty_rotate(t_stack *stack_a, int half_size, int index)
{
	if (half_size > index)
	{
		while (index)
		{
			ft_rotate(stack_a, "ra");
			index--;
		}
	}
	else
	{
		while (stack_a->size - index)
		{
			ft_rev_rotate(stack_a, "rra");
			index++;
		}
	}
}
