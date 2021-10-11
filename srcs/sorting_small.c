#include "../push_swap.h"

void	ft_sort_three(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->numbers_a[0] > stack->numbers_a[1] && stack->numbers_a[1] < stack->numbers_a[2])
	{
		if (stack->numbers_a[0] > stack->numbers_a[2])
			rotate(stack);
		else
			swap(stack);
	}
	else if (stack->numbers_a[0] < stack->numbers_a[1] && stack->numbers_a[1] > stack->numbers_a[2])
	{
		if (stack->numbers_a[0] > stack->numbers_a[2])
			reverse_rotate(stack);
		else
		{
			swap(stack);
			rotate(stack);
		}
	}
	else
	{
		swap(stack);
		reverse_rotate(stack);
	}
}
