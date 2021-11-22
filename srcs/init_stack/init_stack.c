/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:19:41 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:05:49 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(t_stack *stack, int argc, char **argv)
{
	stack = malloc(sizeof(t_stack));
	stack->capacity = argc - 2;
	stack->size = argc - 1;
	stack->top = -1;
	stack->numbers = (int *)ft_calloc(sizeof(int), stack->size);
	stack->numbers = atribute_stack(stack, argv);
	stack->high = 0;
	stack->low = 0;
	stack->high_pos = 0;
	stack->low_pos = 0;
	return (stack);
}

t_stack	*init_stack_b(t_stack *stack_b, int argc)
{
	stack_b = ft_calloc(sizeof(t_stack), 1);
	stack_b->capacity = argc - 2;
	stack_b->size = 0;
	stack_b->numbers = (int *)ft_calloc(sizeof(int), stack_b->capacity);
	stack_b->top = -1;
	return (stack_b);
}
