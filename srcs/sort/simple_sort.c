/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:29:10 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:23:45 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	middle_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top > 2)
	{
		stack_a->low = find_low(stack_a);
		if (stack_a->low_pos == stack_a->top - 1)
			sa_op(stack_a);
		else if (stack_a->low_pos == stack_a->top - 2)
		{
			ra_op(stack_a);
			ra_op(stack_a);
		}
		else if (stack_a->low_pos == 0)
			rra_op(stack_a);
		else if (stack_a->low_pos == 1)
		{
			rra_op(stack_a);
			rra_op(stack_a);
		}
		pb_op(stack_b, stack_a);
	}
	move_top_two(stack_a);
	while (stack_b->top > -1)
		pa_op(stack_a, stack_b);
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->high = find_higher(stack_a);
	stack_a->low = find_low(stack_a);
	if (stack_a->top == 2)
		move_top_two(stack_a);
	else if (stack_a->top >= 3 && stack_a->top <= 5)
		middle_sort(stack_a, stack_b);
}
