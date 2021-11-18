/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 21:32:53 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/10/30 17:54:41 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_op(t_stack *stack)
{
	int	top;
	int	first;

	first = stack->numbers[stack->top];
	top = stack->top;
	while (top > 0)
	{
		stack->numbers[top] = stack->numbers[top - 1];
		top--;
	}
	stack->numbers[top] = first;
}
