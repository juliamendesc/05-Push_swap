#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	int i = 0;

	if (error_handling(argc - 1, argv + 1) == 1)
		ft_exit_ps("Error\n", -1);
	printf("Passed error handling\n");
	ft_fill_stack_a(argc, argv, &stack_a);
	if (ft_A_is_sorted(argc, &stack_a) == -1)
		ft_sorting(&stack_a);
	return (0);
}
