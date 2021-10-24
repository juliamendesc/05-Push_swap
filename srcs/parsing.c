#include "../includes/push_swap.h"

void create_stacks(t_stacks **stack_a, t_stacks **stack_b, int argc, char **argv)
{
	int i;

	*stack_a = NULL;
	*stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back_ps(stack_a, ft_lstnew_ps(ft_atoi(argv[i])));
		i++;
	}
}
