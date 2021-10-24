#include "../includes/push_swap.h"

void sa(t_stacks **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stacks **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_stacks **stack_a, t_stacks **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
