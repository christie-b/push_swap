/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:23:46 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/11 11:06:35 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

static int	hold_number(t_stack *stack_a, int min, int max)
{
	int i;

	i = 0;
	

}

void	sort_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int	hold_first;
	int	hold_second;
	int	i;
	int	j;
	int	min;
	int	max;
	int	move_top;

	min = 0;
	max = 15;
	while (max <= 100)
	{
		while (stack_b->size <= max)
		{
			i = 0;
			while (i < stack_a->size)
			{
				if (stack_a->tab[i] >= min && stack_a->tab[i] <= max)
				{
					hold_first = stack_a->tab[i];
					break ;
				}
				else
					i++;
			}
			j = stack_a->size - 1;
			while (j < stack_a->size)
			{
				if (stack_a->tab[j] >= min && stack_a->tab[j] <= max)
				{
					hold_second = stack_a->tab[j];
					break ;
				}
				else
					j--;
			}
			if (i <= stack_a->size / 2)
			{
				move_top = hold_first;
				while (i)
				{
					ft_rotate(stack_a, "ra");
					i--;
				}
			}
			else
			{
				move_top = hold_second;
				while (j <= stack_a->size)
				{
					ft_rev_rotate(stack_a, "rra");
					j++;
				}
			}
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
				{
					if (stack_a->tab[0] > stack_b->tab[0] && stack_a->tab[0] < stack_b->tab[stack_b->size - 1])
						;
					else
					{
						while (stack_a->tab[0] > stack_b->tab[i])
							i++;
						while (stack_a->tab[0] < stack_b->tab[i])
							i++;
					}
				}
			}
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
		// for (int i = 0; i < stack_a->size; i++)
		// 	printf("A tab[%d] : %d\n", i, stack_a->tab[i]);
		// for (int i = 0; i < stack_b->size; i++)
		// 	printf("B tab[%d] : %d\n", i, stack_b->tab[i]);
		// getchar();
		}
		if (stack_a->size < 5)
		{
			min += 4;
			max += 4;
		}
		else
		{
			min += 16;
			max += 16;
		}
	}
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
	// for (int i = 0; i < stack_a->size; i++)
	// 	printf("FINAL A tab[%d] : %d\n", i, stack_a->tab[i]);
	// for (int i = 0; i < stack_b->size; i++)
	// 	printf("FINAL B tab[%d] : %d\n", i, stack_b->tab[i]);
}