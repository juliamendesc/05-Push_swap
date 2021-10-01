#include "../push_swap.h"

void	ft_fill_stack_a(int argc, char **argv, t_stack *stack)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		stack->numbers_a[j] = ft_atoi(argv[i]);
		j++;
		i++;
	}
}

int	ft_A_is_sorted(int argc, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc -1)
	{
		j = i + 1;
		if (stack->numbers_a[i] < stack->numbers_a[j])
			j++ ;
		else
			return (-1);
		i++;
	}
	return (0);
}
