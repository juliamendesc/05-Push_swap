#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
	t_stacks *stack_a;
	t_stacks *stack_b;
	t_stacks *chunks;

	if (error_handling(argc - 1, argv + 1) == 1)
		ft_exit_ps_simple("Error\n", -1);
	create_stacks(&stack_a, &stack_b, argc, argv);
	if (ft_lstsize_ps(stack_a) <= 5)
		sort_three_to_five(&stack_a, &stack_b);
	if (ft_lstsize_ps(stack_a) > 5)
	{
		chunks = ft_lstnew_ps(get_min(stack_a));
		ft_lstadd_back_ps(&chunks, ft_lstnew_ps(get_max(stack_a)));
		sort_big(&stack_a, &stack_b, &chunks, 0);
	}
	lst_print("stack a\n", stack_a);
	lst_print("stack b\n", stack_b);
	ft_lstclear_ps(&stack_a);
	ft_lstclear_ps(&stack_b);
}
