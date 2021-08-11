/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 10:30:53 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/11 09:09:57 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

void	init_struct1(int nb_w, char **av, t_stack *stack_a, t_stack *stack_b)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	stack_a->capacity = nb_w;
	stack_a->size = stack_a->capacity;
	stack_a->tab = NULL;
	stack_a->tab = malloc(sizeof(int) * stack_a->capacity);
	if (!(stack_a->tab))
		exit(1);
	stack_b->tab = NULL;
	stack_b->tab = malloc(sizeof(int) * stack_a->capacity);
	if (!(stack_b->tab))
		exit(1);
	stack_b->capacity = stack_a->capacity;
	stack_b->size = 0;
	tmp = ft_split(av[1], ' ');
	while (j < nb_w)
	{
		stack_a->tab[i++] = ft_atoi(*tmp);
		j++;
		tmp++;
	}
	while (j)
	{
		tmp--;
		j--;
	}
	ft_free_tab(tmp);
}

void	init_struct2(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	stack_a->capacity = ac - 1;
	stack_a->size = stack_a->capacity;
	stack_b->capacity = ac - 1;
	stack_b->size = 0;
	stack_a->tab = malloc(sizeof(int) * (ac - 1));
	if (!(stack_a->tab))
		exit(1);
	stack_b->tab = malloc(sizeof(int) * (ac - 1));
	if (!stack_b->tab)
		exit(1);
	while (j < ac)
	{
		stack_a->tab[i] = ft_atoi(av[j]);
		i++;
		j++;
	}
}

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	// if (stack_a->capacity == 2)
	// 	sort_two(stack_a);
	// else if (stack_a->capacity == 3)
	// 	sort_three(stack_a);
	// else if (stack_a->capacity == 4)
	// 	sort_four(stack_a, stack_b);
	// else if (stack_a->capacity == 5)
	// 	sort_five(stack_a, stack_b);
	// else if (stack_a->capacity > 5 && stack_a->capacity <= 55)
		// sort_fiftyfive(stack_a, stack_b);
	// else
		// ft_radix(stack_a, stack_b);
	sort_hundred(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		nb_words;

	check_args(ac, av);
	nb_words = count_words(av[1], ' ');
	if (nb_words > 1)
		init_struct1(nb_words, av, &stack_a, &stack_b);
	else
		init_struct2(ac, av, &stack_a, &stack_b);
	simplify_tab(&stack_a);
		// for (int i = 0; i < stack_a.size; i++)
		// 	printf("tab[%d] : %d\n", i, stack_a.tab[i]);
	if (has_dup(&stack_a))
	{
		write(STDERR_FILENO, "Error\n", 6);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		return (0);
	}
	if (!(is_sorted(&stack_a)))
		ft_sort(&stack_a, &stack_b);
	// for (int i = 0; i < stack_a.size; i++)
	// 	printf("tab[%d] : %d\n", i, stack_a.tab[i]);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
