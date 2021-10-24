#include "../includes/push_swap.h"

void pa(t_stacks **stack_a, t_stacks **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void pb(t_stacks **stack_a, t_stacks **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
