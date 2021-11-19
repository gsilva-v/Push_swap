#include "push_swap.h"

int	stacklen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->numbers[i])
		i++;
	return (i);
}
