#include "../includes/push_swap.h"

/*
** This function takes a stack - 'stack_a' and counts its numbers in between the
** first two elements of the stack 'chunks'.
**
** @param	t_stack	*stack_a	- stack to count numbers from.
**
** @param	t_stack	**chunks	- helper stack to know the chunks of stack_a.
**
** @return
** 		- The count_in_between() function returns the number of elements in
** 		between 'chunks's' first two elements that exist in stack_a.
*/
int count_in_between(t_stacks *stack_a, t_stacks *chunks)
{
	t_stacks *duplicate;
	int max_idx;
	int min_idx;

	duplicate = ft_lstdup_ps(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, chunks->number);
	max_idx = ft_stack_find(duplicate, chunks->next->number);
	ft_lstclear_ps(&duplicate);
	return (max_idx - min_idx + 1);
}

/*
** This function will grab the median of 'stack_a' between the first two chunks
** of the stack 'chunks' and add it to 'chunks'.
**
** @line 72-73	The get_new_limit() function starts by creating a duplicated
** 				stack of 'stack_a' - 'duplicate'; and sorting that stack -
** 				'duplicate' will be a sorted version 'stack_a'.
**
** @line 74-75	the function will then try to find the index in duplicate of the
** 				first element of 'chunks' - min_idx; the same happens to
** 				'max_idx' - the index of the second element of 'chunks' in
** 				'duplicate'.
**
** @line 76		after that it is possible to find the index of the median
** 				element of max_idx and min_idx. The calculations are:
** 					(max_idx - min_idx) / 2 + min_idx
**
** @line 76		the new will then be the element whose index in duplicate is of
** 				the number in between max_idx and min_idx.
**
** @line 77-78	new is added to chunks and chunks is sorted so that it contains
** 				all the partitions of stack_a in order.
*/
void get_new_chunk(t_stacks **chunks, t_stacks *stack, int status)
{
	t_stacks *duplicate;
	int min_idx;
	int max_idx;
	int new;

	duplicate = ft_lstdup_ps(stack);
	ft_stack_sort(&duplicate);
	if (status)
	{
		min_idx = ft_stack_find(duplicate, (*chunks)->number);
		max_idx = ft_stack_find(duplicate, (*chunks)->next->number);
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(duplicate, ft_lstsize_ps(duplicate) / 2);
	ft_lstadd_front_ps(chunks, ft_lstnew_ps(new));
	ft_stack_sort(chunks);
	ft_lstclear_ps(&duplicate);
}

/*
** This function splits 'stack_a' to 'stack_b' the numbers whose chunks are
** between the first two elements of the stack 'chunks'.
**
** @param	t_stack	**stack_a	- Stack to be sorted at the end. At the end of
** 								split_a_to_b() function this stacks will contain
** 								only numbers that are bigger than the second
** 								element of 'chunks' or smaller than the first.
**
** @param	t_stack	**stack_b	- Helper stack. At the end of split_a_to_b()
** 								function this stack will contain number between
** 								the first element of 'chunks', and the last
** 								element of 'chunks'.
**
** @param	t_stack	**chunks	- stack containing the chunks desired by both
** 								stacks
**
** example:
** 	- before
** 		chunks: {14, 25, 50, 100}
** 		stack_a: [1, 13] sorted
** 				[14, 100] unsorted
** 		stack_b: empty
** 	- after
** 		chunks: {14, 25, 50, 100}
** 		stack_a: [1, 13] sorted
** 				]25 , 100] unsorted
** 		stack_b: [14, 25] unsorted
**
*/
void split_a_to_b(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks)
{
	int size;
	int first;

	size = count_in_between(*stack_a, chunks);
	while (ft_lstsize_ps(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, chunks);
		while (first--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

/*
** This function iterates stack_a, from the top and finds the first number with
** values between the first and the second number in 'chunks'.
**
** @param	t_stack	*stack_a	- This stack will be iterated in order o find
** 								the position of the first number between
** 								'chunks'.
** @param	t_stack	*chunks		- this stack will serve as the chunks to find
** 								the number in 'stack_a'.
**
** This function returns the extimated number or "ra" instructions necessary for
** the number found in stack_a to be on top.
*/
int get_hold_first(t_stacks *stack_a, t_stacks *chunks)
{
	int first;
	int max;
	int min;

	min = chunks->number;
	max = chunks->next->number;
	first = 0;
	while (stack_a)
	{
		if (stack_a->number >= min && stack_a->number <= max)
			return (first);
		first++;
		stack_a = stack_a->next;
	}
	return (first);
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
	printf("num %d\n", num);
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
void merge_half_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks)
{
	get_new_chunk(&chunks, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, chunks->next->number))
	{
		if ((*stack_b)->number == get_min(*stack_b))
		{
			pa(stack_a, stack_b);
			if ((*stack_b)->number != get_min(*stack_b) && (*stack_b)->number <= chunks->next->number)
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
void merge_sort_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks)
{
	t_stacks *duplicate;

	duplicate = ft_lstdup_ps(*stack_b);
	if (!duplicate)
		return;
	ft_stack_sort(&duplicate);
	while (ft_lstsize_ps(*stack_b))
	{
		if ((*stack_b)->number == duplicate->number)
		{
			pa(stack_a, stack_b);
			duplicate = duplicate->next;
			if (ft_lstsize_ps(*stack_b) && (*stack_b)->number != duplicate->number && (*stack_b)->number != get_max(*stack_b))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else if ((*stack_b)->number == get_max(*stack_b))
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	while (ft_stack_last(*stack_a)->number != chunks->next->number)
		ra(stack_a);
	chunks->next->number = get_next_value(*stack_a, &chunks);
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
int get_next_value(t_stacks *stack_a, t_stacks **chunks)
{
	t_stacks *duplicate;
	int position;
	int minimum;

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
