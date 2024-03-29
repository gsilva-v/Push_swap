/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:20:37 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/01/12 09:59:46 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_range(t_stack *stack_a, int size_range)
{
	size_range = 16;
	if (stack_a->size >= 400)
		size_range = 42;
	return (size_range);
}

int	*create_sorted(int *ordered, t_stack *stack_a)
{
	int	index;

	ordered = (int *)ft_calloc(sizeof(int *), stack_a->capacity);
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

void	clear_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->top > -1)
	{
		sort_b(stack_b);
		pa_op(stack_a, stack_b);
	}
}
