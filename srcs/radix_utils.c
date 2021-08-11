/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 16:56:08 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/06 17:18:37 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	get_lsb(int nb)
{
	int	lsb;

	lsb = nb & 1;
	return (lsb);
}

int	select_bit(int nb, int bit)
{
	nb = nb >> bit;
	return (get_lsb(nb));
}
