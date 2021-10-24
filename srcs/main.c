#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks *stack_a;
	t_stacks *stack_b;
	t_stacks *head;

	if (error_handling(argc - 1, argv + 1) == 1)
		ft_exit_ps_simple("Error\n", -1);
	create_stacks(&stack_a, &stack_b, argc, argv);
	head = stack_a;
	if (ft_lstsize_ps(stack_a) <= 5)
		sort_three_to_five(&stack_a, &stack_b);
	if (ft_lstsize_ps(stack_a) > 5)
		algorithm(&stack_a, &stack_b);
	lst_print("stack a\n", stack_a);
	lst_print("stack b\n", stack_b);
	ft_lstclear_ps(&stack_a);
	ft_lstclear_ps(&stack_b);
}
