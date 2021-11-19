/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:15:41 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/18 18:32:04 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*booble_sort(int *stack, int size)
{
	int	swap;
	int	i;
	int	x;

	i = 0;
	while (i < size)
	{
		x = i;
		while (x < size)
		{
			if (stack[i] > stack[x])
			{
				swap = stack[i];
				stack[i] = stack[x];
				stack[x] = swap;
			}
			x++;
		}
		i++;
	}
	return (stack);
}
