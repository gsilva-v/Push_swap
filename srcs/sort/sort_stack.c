/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 22:42:31 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/18 12:56:16 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top < 2)
		sa_op(stack_a);
	else if (stack_a->top >= 2 && stack_a->top <= 5)
		simple_sort(stack_a, stack_b);
	else
	{
		complex_sort(stack_a, stack_b);
	}
}
