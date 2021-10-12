#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int temp;

	if (stack->numbers_a[1] != -1)
	{
		temp = stack->numbers_a[0];
		stack->numbers_a[0] = stack->numbers_a[1];
		stack->numbers_a[1] = temp;
	}
}

void	rotate(t_stack *stack)
{
	int	temp;
	int i;

	temp = stack->numbers_a[0];
	i = 0;
	while(i < stack->size - 1)
	{
		stack->numbers_a[i] = stack->numbers_a[i + 1];
		i++;
	}
	stack->numbers_a[i] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int temp;
	int i;

	i = stack->size - 1;
	temp = stack->numbers_a[i];
	while(i)
	{
		stack->numbers_a[i] = stack->numbers_a[i - 1];
		i--;
	}
	stack->numbers_a[0] = temp;
}

void	push_to_a(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->size + 1;
	while (i)
	{
		stack->numbers_a[i] = stack->numbers_a[i - 1];
		i--;
	}
	stack->numbers_a[0] = stack->numbers_b[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->numbers_b[i] = stack->numbers_b[i + 1];
		i++;
	}
	stack->numbers_b[i] = -1;
	printf("\npush to a\n");
}

void	push_to_b(t_stack *stack)
{
	int	temp;
	int	i;

	i = stack->size + 1;
	while (i)
	{
		stack->numbers_b[i] = stack->numbers_b[i - 1];
		i--;
	}
	stack->numbers_b[0] = stack->numbers_a[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->numbers_a[i] = stack->numbers_a[i + 1];
		i++;
	}
	stack->numbers_a[i] = -1;
	printf("\npush to b\n");
}
