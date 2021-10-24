#include "./push_swap.h"

int is_sorted(t_stacks *stack)
{
	t_stacks *current;

	current = stack;
	while (current->next)
	{
		if (current->number < current->next->number)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

int get_min(t_stacks *stack)
{
	t_stacks *current;
	int trigger;
	int min;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			min = current->number;
			trigger--;
		}
		else if (min > current->number)
			min = current->number;
		current = current->next;
	}
	return (min);
}

int get_max(t_stacks *stack)
{
	t_stacks *current;
	int trigger;
	int max;

	current = stack;
	trigger = 1;
	while (current)
	{
		if (trigger)
		{
			max = current->number;
			trigger--;
		}
		else if (max < current->number)
			max = current->number;
		current = current->next;
	}
	return (max);
}

int count_middle(t_stacks *stack_a, t_stacks *chunks)
{
	t_stacks *dup;
	int max_index;
	int min_index;

	dup = ft_lstdup_ps(stack_a);
	ft_stack_sort(&dup);
	min_index = ft_stack_find(dup, chunks->number);
	max_index = ft_stack_find(dup, chunks->next->number);
	ft_lstclear_ps(&dup);
	return (max_index - min_index + 1);
}

/*
** This function rotates stack_a until the sorted numbers are found at the
** bottom of the stack sorted in descending order.
**
** @param	t_stack	*stack_a	- stack to sort.
**
** @param	t_stack	**chunks	- helper stack to know values of stack_a that
** 								are sorted.
*/
void rotate_until_sorted(t_stacks **stack_a, t_stacks *chunks)
{
	t_stacks *duplicate;
	int num;
	int index;

	duplicate = ft_lstdup_ps(*stack_a);
	ft_lstadd_front_ps(&duplicate, ft_lstnew_ps(chunks->number));
	ft_stack_sort(&duplicate);
	num = ft_stack_get(duplicate, ft_stack_find(duplicate, chunks->number) - 1);
	ft_lstclear_ps(&duplicate);
	index = ft_stack_find(*stack_a, num);
	if (num == -2147483648 || index == -2147483648)
		return;
	if (index <= ft_lstsize_ps(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->number != num)
			ra(stack_a);
	else
		while (ft_stack_last(*stack_a)->number != num)
			rra(stack_a);
}

/*
** This function is a helper function of merge_sort_to_a() function. It will
** return the minimum number of stack_a that is not sorted, as the new limit.
**
** 		example:
** 			limits: {12, 25, 50, 100}
** 			stack_a: [1, 12] sorted
** 					]12, 100] unsorted
** 			new limits: {13, 25, 50, 100}
**
** @param	t_stack	*stack_a	- stack to get the new limit from.
**
** @param	t_stack	**limits	- stack that contains the old limit.
**
** @return
** 		- the get_next_value() function returns the new limits to be added to
** 		'limits' later in merge_sort_to_a() function.
*/
int get_next_value(t_stacks *stack_a, t_stacks **limits)
{
	t_stacks *duplicate;
	int position;
	int minimum;

	duplicate = ft_lstdup_ps(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*limits)->next->number);
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
