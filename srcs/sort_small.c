#include "../includes/push_swap.h"

/*
** 1st if - 2 3 1 - rra
** 2nd if - 3 1 2 - ra
** 3rd if - 3 2 1 - sa 2 3 1 -> 1st if || 1 3 2 - sa 3 1 2 -> 2nd if || 2 1 3 - sa ok
*/

void sort_three(t_stacks **stack)
{
	while (!is_sorted(*stack))
	{
		if ((*stack)->number < (*stack)->next->number && (*stack)->number > (*stack)->next->next->number)
			rra(stack);
		else if ((*stack)->number > (*stack)->next->number && (*stack)->next->number < (*stack)->next->next->number)
			ra(stack);
		else
			sa(stack);
	}
}

// void sort_three(t_stacks **stack)
// {
// 	int biggest;
// 	int lowest;

// 	biggest = get_max(*stack);
// 	lowest = get_min(*stack);
// 	while (!is_sorted(*stack))
// 	{
// 		if ((*stack)->number != lowest && (*stack)->next->number == biggest)
// 			rra(stack);
// 		else if ((*stack)->number == biggest && (*stack)->next->number == lowest)
// 			ra(stack);
// 		else
// 			sa(stack);
// 	}
// }

/*
** Find lowest, send to b, sort the rest, push b to a
*/

// void push_min_to_b(t_stacks **stack_a, t_stacks **stack_b)
// {
// 	int lowest;

// 	lowest = get_min(*stack_a);
// 	while ((*stack_a)->number != lowest)
// 	{
// 		if ((*stack_a)->number != lowest && (*stack_a)->next->number != lowest)
// 			rra(stack_a);
// 		else
// 			ra(stack_a);
// 	}
// 	pb(stack_a, stack_b);
// }

void sort_four_five(t_stacks **stack_a, t_stacks **stack_b)
{
	int lowest;

	lowest = get_min(*stack_a);
	while (ft_lstsize_ps(*stack_a) > 3)
	{
		while ((*stack_a)->number != lowest)
		{
			if ((*stack_a)->number != lowest && (*stack_a)->next->number != lowest)
				rra(stack_a);
			else
				ra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (ft_lstsize_ps(*stack_b))
		pa(stack_a, stack_b);
}

void sort_three_to_five(t_stacks **stack_a, t_stacks **stack_b)
{
	int size;

	size = ft_lstsize_ps(*stack_a);
	if (is_sorted(*stack_a) == 1)
		return;
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
