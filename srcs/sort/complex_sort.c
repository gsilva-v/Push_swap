/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:50 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:28:54 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_sorted(int *ordered, t_stack *stack_a)
{
	int	index;

	ordered = (int *)malloc(sizeof(int *) * stack_a->capacity);
	if (!ordered)
		return (NULL);
	index = 0;
	while (index < stack_a->size)
	{
		ordered[index] = stack_a->numbers[index];
		index++;
	}
	ordered = booble_sort(ordered, stack_a->size);
	return (ordered);
}

int	*create_range(int *ordered, int *range, int size, t_stack *stack_a)
{
	int	index;
	int	i;

	range = (int *)ft_calloc(sizeof(int *), size);
	i = 0;
	index = 0;
	while (index <= stack_a->top)
	{
		if (ordered[index] % size == 0)
		{
			range[i] = ordered[index];
			i++;
		}
		index++;
	}
	return (range);
}

void	select_push(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	int	i;
	int	next_low;

	next_low = 0;
	i = stack_a->size;
	while (i > 0)
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
	int	i;

	i = 0;
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

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*ordered;
	int	*range;
	int	i;
	int	size;

	size = 20;
	if (stack_a->size >= 400)
		size = 40;
	ordered = create_sorted(ordered, stack_a);
	range = create_range(ordered, range, size, stack_a);
	i = 0;
	size = find_low(stack_a);
	while (!is_sorted(stack_a))
	{
		select_push(stack_a, stack_b, range[i], size);
		size = range[i];
		i++;
	}
	while (stack_b->top > -1)
	{
		sort_b(stack_b);
		pa_op(stack_a, stack_b);
	}
	free(ordered);
	free(range);
}
