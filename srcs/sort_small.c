#include "../includes/push_swap.h"

void	sort_three(t_stacks **stack)
{
	int	maximum;
	int	minimum;

	maximum = get_max(*stack);
	minimum = get_min(*stack);
	while (!is_sorted(*stack))
	{
		if ((*stack)->number != minimum && (*stack)->next->number == maximum)
			rra(stack);
		else if ((*stack)->number == maximum
			&& (*stack)->next->number == minimum)
			ra(stack);
		else
			sa(stack);
	}
}

void	push_min_to_b(t_stacks **stack_a, t_stacks **stack_b)
{
	int	minimum;

	minimum = get_min(*stack_a);
	while ((*stack_a)->number != minimum)
	{
		if ((*stack_a)->number != minimum
			&& (*stack_a)->next->number != minimum)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_four_five(t_stacks **stack_a, t_stacks **stack_b)
{
	while (ft_lstsize_ps(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (ft_lstsize_ps(*stack_b))
		pa(stack_a, stack_b);
}

void	sort_three_to_five(t_stacks **stack_a, t_stacks **stack_b)
{
	int	size;

	size = ft_lstsize_ps(*stack_a);
	if (is_sorted(*stack_a) == 1)
		return ;
	else if (size == 2)
		sa(stack_a);
	else
	{
		if (size == 3)
			sort_three(stack_a);
		else
			sort_four_five(stack_a, stack_b);
	}
}
