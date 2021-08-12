/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 09:46:37 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 12:58:39 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	ft_swap(int *tab, char *str)
{
	int	tmp_a;
	int	tmp_b;

	if (tab)
	{
		tmp_a = tab[0];
		tmp_b = tab[1];
		tab[1] = tmp_a;
		tab[0] = tmp_b;
		write(STDOUT_FILENO, str, ft_strlen(str));
		if (str)
			write(STDOUT_FILENO, "\n", 1);
	}
}

void	ft_push(t_stack *dst, t_stack *src, char *str)
{
	if (src->size && dst->size < dst->capacity)
	{
		ft_memmove((int *)dst->tab + 1, (int *)dst->tab + 0,
			sizeof(int) * (dst->capacity - 1));
		dst->size++;
		dst->tab[0] = src->tab[0];
		ft_memmove((int *)src->tab + 0, (int *)src->tab + 1,
			sizeof(int) * (src->capacity - 1));
		src->size--;
		write(STDOUT_FILENO, str, ft_strlen(str));
		if (str)
			write(STDOUT_FILENO, "\n", 1);
	}
}

void	ft_rotate(t_stack *stack, char *str)
{
	int	tmp;

	tmp = stack->tab[0];
	ft_memmove(stack->tab + 0, stack->tab + 1, sizeof(int)
		* (stack->size - 1));
	stack->tab[stack->size - 1] = tmp;
	write(STDOUT_FILENO, str, ft_strlen(str));
	if (str)
		write(STDOUT_FILENO, "\n", 1);
}

void	ft_rev_rotate(t_stack *stack, char *str)
{
	int	tmp;

	tmp = stack->tab[stack->size - 1];
	ft_memmove(stack->tab + 1, stack->tab + 0, sizeof(int)
		* (stack->size - 1));
	stack->tab[0] = tmp;
	write(STDOUT_FILENO, str, ft_strlen(str));
	if (str)
		write(STDOUT_FILENO, "\n", 1);
}
