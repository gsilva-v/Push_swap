/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atribute_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:26:43 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/22 16:22:53 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*atribute_stack(t_stack *stack, char **argv)
{
	int	i;
	int	size;

	size = stack->capacity;
	i = 1;
	while (size >= 0)
	{
		stack->numbers[size] = ft_atoi(argv[i]);
		stack->top++;
		i++;
		size--;
	}
	return (stack->numbers);
}
