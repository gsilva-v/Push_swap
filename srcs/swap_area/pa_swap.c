/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 20:31:48 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/18 12:42:40 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_op(t_stack *stack_dst, t_stack *stack_src)
{
	// int i = 0;
	// printf("stack dst: ");
	// while (i <= stack_dst->top)
	// {
	// 	printf("%d ", stack_dst->numbers[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// printf("stack src: ");
	// while (i <= stack_src->top)
	// {
	// 	printf("%d ", stack_src->numbers[i]);
	// 	i++;
	// }
	// printf("\n");
	// printf("numero no top de src antes de mexer %d\n", stack_src->top);
	// printf("numero no top de dst antes de mexer %d\n", stack_dst->top);
	stack_dst->top++;
	stack_dst->numbers[stack_dst->top] = stack_src->numbers[stack_src->top];
	stack_src->top--;
	// printf("numero no top de src antes de mexer %d\n", stack_src->top);
	// printf("numero no top de dst antes de mexer %d\n", stack_dst->top);
	// i = 0;
	// printf("stack dst: ");
	// while (i <= stack_dst->top)
	// {
	// 	printf("%d ", stack_dst->numbers[i]);
	// 	i++;
	// }
	// printf("\n");
	// i = 0;
	// printf("stack src: ");
	// while (i <= stack_src->top)
	// {
	// 	printf("%d ", stack_src->numbers[i]);
	// 	i++;
	// }
	// printf("\n");
	write(1, "pa\n", 3);
}
