/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:46:34 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/11 12:22:43 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	sort_tab(t_stack *stack_a, int *tab)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			else
				j++;
		}
		i++;
	}
}

void	simplify_tab(t_stack *stack_a)
{
	int	*tmp_tab;
	int	i;
	int	j;

	i = 0;
	tmp_tab = malloc(sizeof(int) * stack_a->capacity);
	ft_memcpy(tmp_tab, stack_a->tab, stack_a->size * sizeof(int));
	sort_tab(stack_a, tmp_tab);
	j = 0;
	while (j < stack_a->size)
	{
		i = 0;
		while (i < stack_a->size && j < stack_a->size)
		{
			if (tmp_tab[i] == stack_a->tab[j])
			{
				stack_a->tab[j] = i;
				j++;
			}
			i++;
		}
	}
	free(tmp_tab);
}

void	ft_radix2(t_stack *stack_a, t_stack *stack_b, int max_bits, int size_a)
{
	int	i;
	int	j;
	int	size_b;

	j = 0;
	while (j < max_bits)
	{
		i = 0;
		while (i < size_a)
		{
			if (select_bit(stack_a->tab[0], j) == 0)
				ft_push(stack_b, stack_a, "pb");
			else
				ft_rotate(stack_a, "ra");
			i++;
		}
		i = 0;
		size_b = stack_b->size;
		while (i < size_b)
		{
			ft_push(stack_a, stack_b, "pa");
			i++;
		}
		j++;
	}
}

void	ft_radix(t_stack *stack_a, t_stack *stack_b)
{
	int	size_a;
	int	max_num;
	int	max_bits;

	size_a = stack_a->size;
	max_num = size_a - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	ft_radix2(stack_a, stack_b, max_bits, size_a);
}
