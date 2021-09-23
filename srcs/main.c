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

	if (error_handling(argc - 1, argv + 1) == 1)
		ft_exit_ps("Error\n", -1);
	printf("Passed error handling\n");
}
