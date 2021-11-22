/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:56:23 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:18:45 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>//tirar depois

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int	*numbers;
	int	size;
	int	capacity;
	int	**range;
	int	top;
	int	high;
	int	low;
	int	high_pos;
	int	low_pos;
}	t_stack;

/*utils*/

void	*ft_calloc(size_t nbytes, size_t sizemem);
long	ft_atoi(const char *str);
int		ft_isdigit(char c);
int		find_higher(t_stack *stack);
int		find_low(t_stack *stack);
int		find_next_low(t_stack *stack, int max);
int		stacklen(t_stack *stack);

/*validates*/

int		validate_args(int argc, char **argv);
int		is_sorted(t_stack *stack_a);
int		is_rev_sorted(t_stack *stack);
int		is_number(int argc, char **argv);
int		is_different(int argc, char **argv);
int		is_range(int argc, char **argv);

/*init stack*/

t_stack	*init_stack_a(t_stack *stack_a, int argc, char **argv);
t_stack	*init_stack_b(t_stack *stack_b, int argc);
int		*atribute_stack(t_stack *stack, char **argv);

/*destroy stack*/

void	destroy_stacks(t_stack *stack_a, t_stack *stack_b);

/*sort stack*/

int		*booble_sort(int *stack, int size);
void	push_swap(t_stack *stack_a, t_stack *stack_b);

/*moves*/

void	pa_op(t_stack *stack_dst, t_stack *stack_src);
void	pb_op(t_stack *stack_dst, t_stack *stack_src);
void	sa_op(t_stack *stack);
void	sb_op(t_stack *stack);
void	ss_op(t_stack *stack_a, t_stack *stack_b);
void	ra_op(t_stack *stack);
void	rb_op(t_stack *stack);
void	rr_op(t_stack *stack_a, t_stack *stack_b);
void	rra_op(t_stack *stack);
void	rrb_op(t_stack *stack);
void	rrr_op(t_stack *stack_a, t_stack *stack_b);
void	move_top_two(t_stack *stack_a);

/*sorting*/

void	complex_sort(t_stack *stack_, t_stack *stack_b);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
void	sorting(t_stack *stack_a, t_stack *stack_b);
int		what_moves(t_stack *stack_a, int top_b);
void	what_do(t_stack *stack_a, t_stack *stack_b);

/*validates*/

int		validate_args(int argc, char **argv);
int		is_sorted(t_stack *stack_a);
int		is_number(int argc, char **argv);
int		is_different(int argc, char **argv);
int		is_range(int argc, char **argv);

#endif
