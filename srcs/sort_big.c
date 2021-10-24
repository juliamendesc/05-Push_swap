#include "../includes/push_swap.h"

/*
** This function sorts stacks of size bigger than 5. The algorithm in two different
** has two phases: the split phase,
** and the merge phase.
**
** Split Phase:
** 	This phase is focused in pushing to stack_b, the number in between a certain
** 	chunk. The instructions used for this part are "ra", "rra", and "pb". This
** 	phase ends when all the numbers of the chunk are in stack_b.
** 	example:
** 		100 random and unique numbers from 1 to 100.
** 		1st chunk: numbers from 1 to 50 in stack_b.
** 		2nd chunk: numbers from 50 to 100 in stack_a.
**
** Then the program will choose between:
** 	- Merge Back Phase:
** 		This phase occurs if stack_b's size is too big for the Merge Sort Phase.
** 		So what will happen here is that half the values of stack_b will go back
** 		to stack_a - specifically values that are bigger than the median value
** 		of stack_b. This will happen while at the same time trying to sort
** 		what's possible back into stack_a.
**
** 	- Merge Sort Phase:
** 		This phase occurs if stack_b's ready for sorting back into stack_a - has
** 		a few amount of numbers which makes it possible for them to go back
** 		sorted into stack_a.
*/

void sort_big(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks *chunks;
	int maximum;
	int minimum;

	maximum = get_max(*stack_a);
	minimum = get_min(*stack_a);
	chunks = ft_lstnew_ps(minimum);
	ft_lstadd_back_ps(&chunks, ft_lstnew_ps(maximum));
	sorting_chunks(stack_a, stack_b, &chunks, 0);
}

void sorting_chunks(t_stacks **stack_a, t_stacks **stack_b, t_stacks **chunks, int i)
{
	if (ft_lstsize_ps(*chunks) == 1)
	{
		ft_lstclear_ps(chunks);
		return;
	}
	if (ft_lstsize_ps(*chunks) == 2 && count_middle(*stack_a, *chunks) >= MAX_SIZE)
		get_new_chunk(chunks, *stack_a, 1);
	if (!ft_lstsize_ps(*stack_b))
	{
		split_a_to_b(stack_a, stack_b, *chunks);
		rotate_until_sorted(stack_a, *chunks);
	}
	if (ft_lstsize_ps(*stack_b) >= MAX_SIZE)
		merge_half_to_a(stack_a, stack_b, *chunks);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *chunks);
		ft_stack_remove(chunks);
	}
	sorting_chunks(stack_a, stack_b, chunks, ++i);
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
** This function returns the estimated number or "ra" instructions necessary for
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
