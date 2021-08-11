/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboutier <cboutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 09:32:41 by cboutier          #+#    #+#             */
/*   Updated: 2021/08/10 14:22:17 by cboutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int	*tab;
	int	capacity;
	int	size;
}	t_stack;

void		ft_swap(int *tab, char *str);
void		ft_push(t_stack *dst, t_stack *src, char *str);
void		ft_rotate(t_stack *stack, char *str);
void		ft_rev_rotate(t_stack *stack, char *str);

/* CHECK */
int			has_dup(t_stack *stack);
void		check_args(int ac, char **av);
int			is_sorted(t_stack *stack);

/* SORT */
void		sort_two(t_stack *stack);
void		sort_three(t_stack *stack);
void		sort_four(t_stack *stack_a, t_stack *stack_b);
void		sort_four_rotate(t_stack *stack_a, t_stack *stack_b);

void		sort_five(t_stack *stack_a, t_stack *stack_b);
void		sort_five_rotate(t_stack *stack_a, t_stack *stack_b, int min);
void		sort_fiftyfive(t_stack *stack_a, t_stack *stack_b);
void		sort_fiftyfive_rotate(t_stack *stack_a, int half_size, int index);
int			get_min(t_stack *stack, int size);
int			get_max(t_stack *stack, int size);

void		sort_hundred(t_stack *stack_a, t_stack *stack_b);

/* RADIX */
int			select_bit(int nb, int bit);
int			get_lsb(int nb);
void		simplify_tab(t_stack *stack_a);
void		sort_tab(t_stack *stack_a, int *tab);
void		ft_radix(t_stack *stack_a, t_stack *stack_b);
void		ft_radix2(t_stack *stack_a, t_stack *stack_b, int max_bits, int size_a);

/* UTILS */
void		put_error(void);
int			ft_strlen(char *str);
int			ft_isdigit(int ac, char **av);
int			ft_isdigit2(char **av);
int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(const char *str);
int			count_words(char *str, char sep);
char		**ft_split(char const *s, char c);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_free_stack(t_stack *stack);
int			ft_free_tab(char **tab);

#endif
