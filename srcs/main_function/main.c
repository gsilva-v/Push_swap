/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:49:35 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/20 13:09:56 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!validate_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = init_stack_a(stack_a, argc, argv);
	stack_b = init_stack_b(stack_a, argc);
	push_swap(stack_a, stack_b);
	// destroy_stacks(stack_a, stack_b);
	return (0);
}