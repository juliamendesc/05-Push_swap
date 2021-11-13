/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:42:24 by julcarva          #+#    #+#             */
/*   Updated: 2021/11/13 18:52:28 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Chunks create partitions from breakpoints in the stack. We iterate through
** the sorted dup to get the min and max numbers' indexes (1st and 2nd).
** We return the difference between indexes + 1 (given than the 1st is 0).
*/

int get_chunk_difference(t_stacks *stack_a, t_stacks *chunks)
{
	t_stacks *dup;
	int max_idx;
	int min_idx;

	dup = ft_lstdup_ps(stack_a);
	ft_stack_sort(&dup);
	min_idx = ft_stack_find_index(dup, chunks->number);
	max_idx = ft_stack_find_index(dup, chunks->next->number);
	ft_lstclear_ps(&dup);
	return (max_idx - min_idx + 1);
}
/*
** This function will act differently if called when control
** is 1 (when chunks has 2 items and the differences between
** indexes is bigger than 20 - which means the chunk is too
** big to be sorted efficiently and we should look for a new
** one) or when control is 0 (when a chunk is sorted and
** ready to be merged to stack a, thus a chunk is needed for
** merging). We add +1 in the end to guarantee
** we will include the max_index.
*/

void get_new_chunk_from_median(t_stacks **chunks,
															 t_stacks *stack, int control)
{
	t_stacks *dup;
	int min_idx;
	int max_idx;
	int new;

	dup = ft_lstdup_ps(stack);
	ft_stack_sort(&dup);
	if (control)
	{
		min_idx = ft_stack_find_index(dup, (*chunks)->number);
		max_idx = ft_stack_find_index(dup, (*chunks)->next->number);
		new = ft_stack_get_position(dup,
																(min_idx + ((max_idx - min_idx) / 2) + 1));
	}
	else
		new = ft_stack_get_position(dup, ft_lstsize_ps(dup) / 2);
	ft_lstclear_ps(&dup);
	ft_lstadd_front_ps(chunks, ft_lstnew_ps(new));
	ft_stack_sort(chunks);
}

/*
** Stack a will be split into stack b according to each chunk size.
** Stack b will have only the numbers in the chunks' range.
** Numbers bigger than max_idx and min_idx will remain in stack a.
*/

void split_a_to_b(t_stacks **stack_a,
									t_stacks **stack_b, t_stacks *chunks)
{
	int size;
	int first;
	int len;

	size = get_chunk_difference(*stack_a, chunks);
	len = ft_lstsize_ps(*stack_b);
	while (len < size)
	{
		first = get_number_in_chunk(*stack_a, chunks);
		while (first--)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
}

/*
** The function will iterate through stack a to check if the numbers are within
** the chunk's range. If the number belongs to this range, it returns the counter
** used to estimate how many rotations will be necessary to get to that number
** on top of stack a and then be pushed to stack b.
*/

int get_number_in_chunk(t_stacks *stack_a, t_stacks *chunks)
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
** The function will iterate through stack a and check if the numbers in
** chunks are closer to the top or the bottom of the stack.
** It uses a sorted duplicate of stack a to check if the numbers in stack a
** are already sorted.
** If the number or index are not in the stack, num or index will be set as
** the min int and the function returns without doing anything.
** If the index is less than half the stack (number closer to top), it rotates
** Else (number closer to bottom) it reverse rotates
*/

void rotate_until_sorted(t_stacks **stack_a, t_stacks *chunks)
{
	t_stacks *dup;
	int num;
	int index;
	int half;

	dup = ft_lstdup_ps(*stack_a);
	ft_lstadd_front_ps(&dup, ft_lstnew_ps(chunks->number));
	ft_stack_sort(&dup);
	num = ft_stack_get_position(dup,
															ft_stack_find_index(dup, chunks->number) - 1);
	ft_lstclear_ps(&dup);
	index = ft_stack_find_index(*stack_a, num);
	half = ft_lstsize_ps(*stack_a) / 2;
	if (num == -2147483648 || index == -2147483648)
		return;
	if (index <= half)
		while (ft_stack_last(*stack_a)->number != num)
			ra(stack_a);
	else
		while (ft_stack_last(*stack_a)->number != num)
			rra(stack_a);
}
