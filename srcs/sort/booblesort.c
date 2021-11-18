/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:15:41 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/16 15:28:01 by matrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*booble_sort(int *stack)
{
	int	swap;
	int	size;
	int	i;
	int	x;

	i = 0;
	size = 0;
	while (stack[size++])
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
