/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_higher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:17:54 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/19 15:50:39 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_higher(t_stack *stack)
{
	int	i;
	int	higher;

	higher = stack->numbers[0];
	stack->high = higher;
	stack->high_pos = 0;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->numbers[i] > higher)
		{
			higher = stack->numbers[i];
			stack->high_pos = i;
		}	
		i++;
	}
	return (higher);
}
