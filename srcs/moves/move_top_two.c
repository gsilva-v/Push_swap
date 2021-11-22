/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:22:37 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:23:09 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_two(t_stack *stack_a)
{
	stack_a->high = find_higher(stack_a);
	stack_a->low = find_low(stack_a);
	if (stack_a->high_pos == 2 && stack_a->low_pos == 0)
	{
		ra_op(stack_a);
		sa_op(stack_a);
	}
	else if (stack_a->high_pos == 2 && stack_a->low_pos == 1)
		ra_op(stack_a);
	else if (stack_a->high_pos == 1 && stack_a->low_pos == 0)
		rra_op(stack_a);
	else if (stack_a->high_pos == 1 && stack_a->low_pos == 2)
	{
		sa_op(stack_a);
		ra_op(stack_a);
	}
	else if (stack_a->high_pos == 0 && stack_a->low_pos == 1)
		sa_op(stack_a);
}
