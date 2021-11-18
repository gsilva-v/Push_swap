/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:49:33 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/05 18:12:33 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	destroy_stacks(t_stack *stack_a, t_stack *stack_b)
{
	// printf("free 1\n");
	free(stack_a->numbers);
	// stack_a->numbers = NULL;
	// printf("free 2\n");
	free(stack_a);
	// printf("free 3\n");
	free(stack_b->numbers);
	// stack_b->numbers = NULL;
	// printf("free 4\n");
	free(stack_b);
	// printf("free completo\n");
}
