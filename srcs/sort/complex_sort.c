/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:50 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/01/12 09:59:08 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*ordered;
	int	*range;
	int	i;
	int	min;
	int	size_range;

	ordered = NULL;
	range = NULL;
	size_range = 0;
	size_range = set_range(stack_a, size_range);
	ordered = create_sorted(ordered, stack_a);
	range = create_range(ordered, range, size_range + 1, stack_a);
	i = 0;
	min = find_low(stack_a);
	while (!is_sorted(stack_a))
	{
		select_push(stack_a, stack_b, range[i], min);
		min = range[i];
		i++;
	}
	clear_b(stack_a, stack_b);
	free(ordered);
	free(range);
}

void	select_push(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	int	i;
	int	next_low;

	next_low = 0;
	i = stack_a->size;
	while (i > 1)
	{
		if (stack_a->numbers[stack_a->top] < max
			&& stack_a->numbers[stack_a->top] >= min)
			pb_op(stack_b, stack_a);
		else
		{
			next_low = find_next_low(stack_a, max);
			if (next_low > stack_a->top / 2)
				ra_op(stack_a);
			else
				rra_op(stack_a);
		}
		find_low(stack_a);
		if (stack_a->low_pos == stack_a->top)
			pb_op(stack_b, stack_a);
		i--;
	}
}

void	sort_b(t_stack *stack_b)
{
	find_higher(stack_b);
	if (stack_b->high_pos >= stack_b->top / 2)
	{
		while (stack_b->high_pos < stack_b->top)
		{	
			rb_op(stack_b);
			stack_b->high_pos++;
		}
	}
	else
	{
		if (stack_b->high_pos == 0)
			rrb_op(stack_b);
		else
		{
			while (stack_b->high_pos >= 0)
			{
				rrb_op(stack_b);
				stack_b->high_pos--;
			}
		}	
	}
}
