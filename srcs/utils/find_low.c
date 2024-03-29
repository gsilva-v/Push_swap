/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_low.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:18:29 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:20:43 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_low(t_stack *stack)
{
	int	i;
	int	smaller;

	smaller = stack->numbers[stack->top];
	stack->low = smaller;
	stack->low_pos = stack->top;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->numbers[i] < smaller)
		{
			smaller = stack->numbers[i];
			stack->low_pos = i;
		}
		i++;
	}
	return (smaller);
}

int	find_next_low(t_stack *stack, int max)
{
	int	pos;

	pos = stack->top;
	while (pos > -1)
	{
		if (stack->numbers[pos] < max)
			return (pos);
		pos--;
	}
	return (pos);
}
