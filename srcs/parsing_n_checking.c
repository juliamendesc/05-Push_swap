#include "../push_swap.h"

void	ft_fill_stack_a(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	stack->size = argc - 1;
	while (i < stack->size)
	{
		stack->numbers_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	ft_A_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers_a[i] < stack->numbers_a[i + 1])
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
