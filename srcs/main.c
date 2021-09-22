#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int	i;
	int j;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	j = 1;

	while (i < argc)
	{
		if (error_handling(argc, argv) == -1)
			ft_exit_ps("Error\n", -1);
		i++;
	}
	printf("Passed error handling\n");
}
