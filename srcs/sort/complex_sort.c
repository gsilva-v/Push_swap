/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:27:50 by gsilva-v          #+#    #+#             */
/*   Updated: 2021/11/26 19:13:09 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*ordered;
	int	range;
	int	i;
	int	size;
	int	size_range;

	// size_range = set_range(stack_a, size_range);
	size_range = stack_a->size / 2;
	ordered = create_sorted(ordered, stack_a);
	range = ordered[stack_a->size / 2];
	i = 0;
	size = find_low(stack_a);
	// while (!is_sorted(stack_a))
	// {
		select_push(stack_a, stack_b, range);
	// }
	// printf("segundo loop\n");
	while (stack_b->size)
	{
		sort_b(stack_a, stack_b);
		pa_op(stack_a, stack_b);
		// i = stack_a->top;
		// printf("stack a:\n");
		// while(i > -1)
		// {
		// 	printf("posição %d: %d\n", i, stack_a->numbers[i]);
		// 	i--;
		// }
		// i = stack_b->top;
		// printf("stack b:\n");
		// while(i > -1)
		// {
		// 	printf("posição %d: %d\n", i, stack_b->numbers[i]);
		// 	i--;
		// }
		// exit(0);
	}
	free(ordered);
}

void	select_push(t_stack *stack_a, t_stack *stack_b, int max)
{
	int	i;
	int	next_low;

	next_low = 0;
	i = (stack_a->size / 2);
	stack_a->high = find_higher(stack_a);
	stack_a->low = find_low(stack_a);
	// printf ("high: %d\n", stack_a->high);
	// printf ("low: %d\n", stack_a->low);
	// printf("max: %d\n", max);
	// printf("min: %d\n", min);
	// exit(0);

	while (stack_a->top > i)
	{
		if (stack_a->numbers[stack_a->top] < max)
			pb_op(stack_b, stack_a);
		else
		{
			next_low = find_next_low(stack_a, max);
			if (next_low > stack_a->top / 2)
				ra_op(stack_a);
			else
				rra_op(stack_a);
		}
	}
	while (stack_a->top > 2)
	{
		if (stack_a->numbers[stack_a->top] > max)
			pb_op(stack_b, stack_a);
		else
		{
			next_low = find_next_low(stack_a, max);
			if (next_low > stack_a->top / 2)
				ra_op(stack_a);
			else
				rra_op(stack_a);
		}
	}
}

int	get_right_position(t_stack *stack, int nbr)
{
	int pos;

	pos = 0;
	while (!(nbr > stack->numbers[pos] && nbr < stack->numbers[pos + 1]) && pos < (stack->size - 2))
		pos++;
	return (pos);	
}

void put_in_top(t_stack *stack_a, t_stack *stack_b, int to_top_a, int to_top_b)
{
	int index_a;
	int index_b;

	index_a = get_right_position(stack_a, to_top_a);
	index_b = get_right_position(stack_b, to_top_b);
	// printf("index_a: %d\n", index_a);
	// printf("index_b: %d\n", index_b);
	if (index_b > -1)
	{
		if(index_b >= stack_b->size / 2)
			while(stack_b->numbers[stack_b->top] != to_top_b)
				rb_op(stack_b);
		else
			while(stack_b->numbers[stack_b->top] != to_top_b)
			{
				printf("%d\n", to_top_b);
				printf("%d\n", stack_b->numbers[stack_b->top]);
				rrb_op(stack_b);
				// sleep(1 / 2);
			}
	}
	if (index_a > -1)
	{
		if(index_a >= stack_a->size / 2)
			while(stack_a->numbers[stack_a->top] != to_top_a)
				ra_op(stack_a);
		else
			while(stack_a->numbers[stack_a->top] != to_top_a)
				rra_op(stack_a);
	}
}

void	sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int pos;
	int moves;
	int aux_a;
	int aux_b;
	int i;

	pos = 0;
	i = 0;
	moves = INT_MAX;
	while(i <= stack_b->size)
	{
		// printf("parou aqui\n");
		aux_b = stack_b->numbers[i];
		pos = get_right_position(stack_a, aux_b);
		aux_a = stack_a->numbers[pos];
		if (moves_count(stack_a, aux_a) + moves_count(stack_b, aux_b) < moves)
		{
			stack_a->best_nbr = aux_a;
			stack_b->best_nbr = aux_b;
			moves = moves_count(stack_a, aux_a) + moves_count(stack_b, aux_b);
		}
		i++;
	}
	// put_in_top(stack_a, stack_b, stack_a->best_nbr, stack_b->best_nbr);
}
