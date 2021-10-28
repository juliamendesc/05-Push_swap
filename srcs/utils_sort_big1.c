#include "../includes/push_swap.h"

/*
** This function takes a stack - 'stack_b' - and all its numbers above the
** second element of 'chunks' are pushed back to 'stack_a'
** 		example:
** 			50 random numbers between 1 and 50;
** 			stack_a: ]25, 50] unsorted
** 			stack_b: [1, 25] unsorted
** 			chunks: {1, 13, 25, 50}
** 		all numbers bigger than 13 have to go back to stack_a.
**
** @param	t_stack	**stack_a	- stack where the numbers will go back to.
** @param	t_stack	**stack_b	- stack where the numbers above the second
** 								element of 'chunks' will have to move out of.
** @param	t_stack	*chunks		- stack that contains the chunks of the
** 								partitions of the other stacks.
*/
void	merge_half_to_a(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *chunks)
{
	get_new_chunk(&chunks, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, chunks->next->number))
	{
		if ((*stack_b)->number == get_min(*stack_b))
		{
			pa(stack_a, stack_b);
			if ((*stack_b)->number != get_min(*stack_b)
				&& (*stack_b)->number <= chunks->next->number)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else if ((*stack_b)->number > chunks->next->number)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}

void	merge_sort_to_a_helper(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *duplicate)
{
	if ((*stack_b)->number == duplicate->number)
	{
		pa(stack_a, stack_b);
		duplicate = duplicate->next;
		if (ft_lstsize_ps(*stack_b) && (*stack_b)->number != duplicate->number
			&& (*stack_b)->number != get_max(*stack_b))
			rr(stack_a, stack_b);
		else
			ra(stack_a);
	}
	else if ((*stack_b)->number == get_max(*stack_b))
		pa(stack_a, stack_b);
	else
		rb(stack_b);
}

/*
** This function merges the rest of stack_b' to 'stack_a' in a sorted matter.
**
** @param	t_stack	**stack_a	- stack where the numbers will go back to
** 								sorted.
** @param	t_stack	**stack_b	- stack where the numbers where. At the end
** 								this stack will be empty.
** @param	t_stack	*chunks		- stack that contains the chunks of the
** 								partitions of the other stacks.
*/
void	merge_sort_to_a(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *chunks)
{
	t_stacks	*duplicate;

	duplicate = ft_lstdup_ps(*stack_b);
	if (!duplicate)
		return ;
	ft_stack_sort(&duplicate);
	while (ft_lstsize_ps(*stack_b))
	{
		merge_sort_to_a_helper(stack_a, stack_b, duplicate);
	}
	while (ft_stack_last(*stack_a)->number != chunks->next->number)
		ra(stack_a);
	chunks->next->number = get_next_value(*stack_a, &chunks);
	while (duplicate->previous != NULL)
		duplicate = duplicate->previous;
	ft_lstclear_ps(&duplicate);
}

/*
** This function is a helper function of merge_sort_to_a() function. It will
** return the minimum number of stack_a that is not sorted, as the new limit.
**
** 		example:
** 			chunks: {12, 25, 50, 100}
** 			stack_a: [1, 12] sorted
** 					]12, 100] unsorted
** 			new chunks: {13, 25, 50, 100}
**
** @param	t_stack	*stack_a	- stack to get the new limit from.
**
** @param	t_stack	**chunks	- stack that contains the old limit.
**
** @return
** 		- the get_next_value() function returns the new chunks to be added to
** 		'chunks' later in merge_sort_to_a() function.
*/
int	get_next_value(t_stacks *stack_a, t_stacks **chunks)
{
	t_stacks	*duplicate;
	int			position;
	int			minimum;

	duplicate = ft_lstdup_ps(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*chunks)->next->number);
	minimum = ft_stack_get(duplicate, position);
	if (minimum == ft_stack_last(duplicate)->number)
	{
		ft_lstclear_ps(&duplicate);
		return (minimum);
	}
	else
		minimum = ft_stack_get(duplicate, position + 1);
	ft_lstclear_ps(&duplicate);
	return (minimum);
}
