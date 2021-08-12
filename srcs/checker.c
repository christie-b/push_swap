/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:07:56 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/12 13:19:03 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	is_valid_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "sa")
			|| !ft_strcmp(cmd, "sb")
			|| !ft_strcmp(cmd, "ss")
			|| !ft_strcmp(cmd, "pa")
			|| !ft_strcmp(cmd, "pb")
			|| !ft_strcmp(cmd, "ra")
			|| !ft_strcmp(cmd, "rb")
			|| !ft_strcmp(cmd, "rr")
			|| !ft_strcmp(cmd, "rra")
			|| !ft_strcmp(cmd, "rrb")
			|| !ft_strcmp(cmd, "rrr"))
		return (1);
	return (0);
}

int	exec_cmd2(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(cmd, "rr") == 0)
	{
		ft_rotate(stack_a, NULL);
		ft_rotate(stack_b, NULL);
	}
	else if (ft_strcmp(cmd, "rra") == 0)
		ft_rev_rotate(stack_a, NULL);
	else if (ft_strcmp(cmd, "rrb") == 0)
		ft_rev_rotate(stack_b, NULL);
	else if (ft_strcmp(cmd, "rrr") == 0)
	{
		ft_rev_rotate(stack_a, NULL);
		ft_rev_rotate(stack_b, NULL);
	}
	return (0);
}

int	exec_cmd1(char *cmd, t_stack *stack_a, t_stack *stack_b)
{
	if (!(is_valid_cmd(cmd)))
		put_error();
	if (ft_strcmp(cmd, "sa") == 0)
		ft_swap(stack_a->tab, NULL);
	else if (ft_strcmp(cmd, "sb") == 0)
		ft_swap(stack_b->tab, NULL);
	else if (ft_strcmp(cmd, "ss") == 0)
	{
		ft_swap(stack_a->tab, NULL);
		ft_swap(stack_b->tab, NULL);
	}
	else if (ft_strcmp(cmd, "pa") == 0)
		ft_push(stack_a, stack_b, NULL);
	else if (ft_strcmp(cmd, "pb") == 0)
		ft_push(stack_b, stack_a, NULL);
	else if (ft_strcmp(cmd, "ra") == 0)
		ft_rotate(stack_a, NULL);
	else if (ft_strcmp(cmd, "rb") == 0)
		ft_rotate(stack_b, NULL);
	else
		return (exec_cmd2(cmd, stack_a, stack_b));
	return (0);
}

int	read_cmds(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;
	int		ret_exec;
	char	*buf;

	ret_exec = 0;
	ret = 1;
	while (ret_exec == 0 && ret > 0)
	{
		ret = get_next_line(STDIN_FILENO, &buf);
		if (ret > 0)
			ret_exec = exec_cmd1(buf, stack_a, stack_b);
		free(buf);
	}
	return (ret_exec);
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
	if (has_dup(&stack_a))
	{
		write(STDERR_FILENO, "Error\n", 6);
		ft_free_stack(&stack_a);
		ft_free_stack(&stack_b);
		return (1);
	}
	simplify_tab(&stack_a);
	if (stack_a.capacity == 0)
		put_error();
	if (read_cmds(&stack_a, &stack_b) == 0)
	{
		if (is_sorted(&stack_a) && stack_b.size == 0)
			write(STDOUT_FILENO, "OK\n", 3);
		else
			write(STDOUT_FILENO, "KO\n", 3);
	}
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}