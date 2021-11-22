/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:33 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:19:07 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->numbers);
	stack_a->numbers = NULL;
	free(stack_a);
	free(stack_b->numbers);
	stack_b->numbers = NULL;
	free(stack_b);
}
