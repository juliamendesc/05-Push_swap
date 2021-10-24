#include "./push_swap.h"

/*
** This function will grab the median of 'stack_a' between the first two chunks
** of the stack 'chunks' and add it to 'chunks'.
**
** @line 57	The get_new_limit() function starts by creating a duplicated
** 				stack of 'stack_a' - 'dup'; and sorting that stack -
** 				'dup' will be a sorted version 'stack_a'.
**
** @line 59-64	the function will then try to find the index in duplicate of the
** 				first element of 'chunks' - min_idx; the same happens to
** 				'max_idx' - the index of the second element of 'chunks' in
** 				'dup'.
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
void get_new_chunk(t_stacks **chunks, t_stacks *stack_a, int status)
{
	t_stacks *dup;
	int min_index;
	int max_index;
	int new;

	dup = ft_lstdup_ps(stack_a);
	ft_stack_sort(chunks);
	if (status)
	{
		min_index = ft_stack_find(dup, (*chunks)->number);
		max_index = ft_stack_find(dup, (*chunks)->next->number);
		new = ft_stack_get_position(dup, ((max_index - min_index) / 2 + min_index + 3));
	}
	else
		new = ft_stack_get_position(dup, ft_lstsize_ps(dup) / 2);
	ft_lstadd_front_ps(chunks, ft_lstnew_ps(new));
	ft_stack_sort(chunks);
	ft_lstclear_ps(&dup);
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

	size = count_middle(*stack_a, chunks);
	while (ft_lstsize_ps(*stack_b) < size)
	{
		first = get_hold_first(*stack_a, chunks);
		while (first--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
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
	num = ft_stack_get_position(duplicate, ft_stack_find(duplicate, chunks->number) - 1);
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
