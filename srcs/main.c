#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack;
	int i = 0;

	if (error_handling(argc - 1, argv + 1) == 1)
		ft_exit_ps("Error\n", -1);
	ft_fill_stack_a(argc, argv, &stack);
	if (ft_A_is_sorted(&stack) == 0)
	{
		if (argc - 1 == 3)
		 	ft_sort_three(&stack);
		else
			printf("main-not sorted\n");
	}
	i = 0;
	while (i < stack.size)
	{
		printf("stack a %d\n", stack.numbers_a[i]);
		i++;
	}
	return (0);
}
