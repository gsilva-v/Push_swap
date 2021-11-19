/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:31:48 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/19 16:49:47 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_op(t_stack *stack_dst, t_stack *stack_src)
{
	stack_dst->size++;
	stack_src->size--;
	stack_dst->top++;
	stack_dst->numbers[stack_dst->top] = stack_src->numbers[stack_src->top];
	stack_src->top--;
	write(1, "pa\n", 3);
}
