#include "push_swap.h"

int	*create_sorted(int *ordered, t_stack *stack_a)
{
	int	index;

	ordered = (int *)malloc(sizeof(int *) * stack_a->capacity);
	if (!ordered)
		return NULL;
	index = 0;
	while (index < stack_a->size)
	{
		ordered[index] = stack_a->numbers[index];
		index++;
	}
	ordered = booble_sort(ordered, stack_a->size);
	return (ordered);
}

int *create_range(int *ordered, int *range, int size_range, t_stack *stack_a)
{
	int index;
	int i;

	range = (int *)malloc(sizeof(char *) * size_range);
	i = 0;
	index = 0;
	while (index <= stack_a->top)
	{
			if (ordered[index] % size_range == 0)
			{
				range[i] = ordered[index];
				i++;				
			}
		index++;
	}
	return (range);
}

int	select_push(t_stack *stack_a, t_stack *stack_b, int max, int min)
{
	int count;
	int i;
	int index;
	// int j;
	index = 0;
	count = 0;
	i = stack_a->size;
	while (i > 0)
	{
		if (stack_a->numbers[stack_a->top] < max && stack_a->numbers[stack_a->top] >= min)
		{
			// j = i;
			// i = stack_a->top;
			// printf("stack a antes:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_a->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			pb_op(stack_b, stack_a);
			// i = stack_a->top;
			// printf("stack a depois:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_a->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			count++;
			// i = stack_b->top;
			// printf("stack b:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_b->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			// i = j;
			// sleep(1);
		}	
		else
		{
			find_low(stack_a);
			if(stack_a->low_pos > stack_a->top / 2)
				ra_op(stack_a);
			else
				rra_op(stack_a);
		}
		find_low(stack_a);
		if (stack_a->low_pos == stack_a->top)
		{
			// j = i;
			// i = stack_a->top;
			// printf("stack a antes:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_a->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			pb_op(stack_b, stack_a);
			// i = stack_a->top;
			// printf("stack a depois:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_a->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			// i = stack_b->top;
			// printf("stack b:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_b->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			// i = j;
		}	
		i--;
	}
	return (count);
}

void	sort_b(t_stack *stack_b)
{
	int pos;

	find_higher(stack_b);
	pos = stack_b->high_pos;
	// printf("high encontrado: %d\n", i);
	// printf("high_pos de b: %d\n", stack_b->high_pos);
	// printf("top de b: %d\n", stack_b->top);
	// i = stack_b->top;
	// printf("stack b:\n");
	// while (i > -1)
	// {
	// 	printf("posição %d\t%d \n", i, stack_b->numbers[i--]);
	// }
	// printf("\n");

	if(stack_b->high_pos >= stack_b->top / 2)
	{
			while (stack_b->high_pos <= stack_b->top)
			{	
				rb_op(stack_b);
				stack_b->high_pos++;
			}
	}
	else
	{
		while (stack_b->high_pos >= 0)
		{
			// printf("high_pos: %d\n", stack_b->high_pos);
			rrb_op(stack_b);
			stack_b->high_pos--;
			// sleep(1);
		}
		if (stack_b->high_pos == 0)
			rrb_op(stack_b);
	}
	// find_higher(stack_b);
	// printf("high_pos de b depois da movimentação: %d\n", stack_b->high_pos);
}


void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int *ordered;
	int *range;
	int i;
	int index;
	int	size;

	size = stack_a->size / 5;
// tentar melhorar a definição de size
	// size = 2;
	// if (stack_a->size > 10 && stack_a->size <= 99)
	// 	size = 5;
	// else if (stack_a->size >= 100 && stack_a->size <= 250)
	// 	size = 20;
	// else if (stack_a->size > 250)
	// 	size = 50;
	ordered = create_sorted(ordered, stack_a);
	range = create_range(ordered, range, size, stack_a);
//outra função
	// i = stack_a->top;
	// printf("stack a inicial:\n");
	// while (i > -1)
	// {
	// 	printf("posição %d\t%d \n", i, stack_a->numbers[i]);
	// 	i--;
	// }
	// printf("\n");
	// int min = find_low(stack_a);
	// while (range[i])
	// {
	// 	printf("%d ",range[i++]);
	// }
	i = 0;
	int j = 0;
	size = find_low(stack_a);
	while (!is_sorted(stack_a))
	{
		// printf("min: %d\n", min);
		// printf("max: %d\n", range[i]);
		index = select_push(stack_a, stack_b, range[i], size);
		size = index;
		while (size--)
		{
			sort_b(stack_b);
			// j = i;
			// i = stack_b->top;
			// printf("stack b:\n");
			// while (i > -1)
			// {
			// 	printf("posição %d\t%d \n", i, stack_b->numbers[i]);
			// 	i--;
			// }
			// printf("\n");
			// i = j;
			pa_op(stack_a, stack_b);
			// sleep(1);

		}
		if(!is_sorted(stack_a))
		{
			// printf("index: %d\n", index);
			while (index--)
				pb_op(stack_b, stack_a);
			
		}
		else
		{
			// printf("erro aqui na vez %d\n", i);
			// printf("erro entrando aqui na vez %d\n", i);
			while (stack_b->size)
				pa_op(stack_a, stack_b);
		}
		size = range[i];
		i++;
	}
	// printf("saiu do loop\n");
	// i = stack_a->top;
	// printf("stack a final: \n");
	// while (i > -1)
	// {
	// 	printf("posição %d\t%d \n", i, stack_a->numbers[i--]);
	// }
	// printf("\n");

	// i = stack_b->top;
	// printf("stack b:\n");
	// while (i > -1)
	// {
	// 	printf("posição %d\t%d \n", i, stack_b->numbers[i--]);
	// }
	// printf("\n");

}
