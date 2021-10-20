#include "./push_swap.h"

void ra(t_stacks **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void rb(t_stacks **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void rr(t_stacks **stack_a, t_stacks **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
