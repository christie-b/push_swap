/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:11:37 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/07 16:13:20 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size == 1 || stack->size == 0)
		return (1);
	while (i < stack->size - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
