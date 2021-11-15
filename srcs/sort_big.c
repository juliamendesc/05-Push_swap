/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:48:51 by julcarva          #+#    #+#             */
/*   Updated: 2021/11/15 15:34:38 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks **chunks, int i)
{
	if (ft_lstsize_ps(*chunks) == 1)
	{
		ft_lstclear_ps(chunks);
		return ;
	}
	if (ft_lstsize_ps(*chunks) == 2 && get_chunk_difference(*stack_a, *chunks) >= MAX_SIZE)
		get_new_chunk_from_median(chunks, *stack_a, 1);
	if (!ft_lstsize_ps(*stack_b))
	{
		split_a_to_b(stack_a, stack_b, *chunks);
		rotate_until_sorted(stack_a, *chunks);
	}
	if(ft_lstsize_ps(*stack_b) >= MAX_SIZE)
		merge_half_to_a(stack_a, stack_b, *chunks);
	else
	{
		merge_sort_to_a(stack_a, stack_b, *chunks);
		ft_stack_remove_item(chunks);
	}
	sort_big(stack_a, stack_b, chunks, ++i);
}

/*
** Pushes the numbers outside the chunk's range from stack b back to stack a
** to be handled in the next chunk. This push happens while stack b has
** numbers out of range between the first and second chunk index number.
** Then, it compares if the numbers in stack b are different than its min
** and smaller or equal to the chunk's bigger limit. If so, it reverses rotate
** If the numbers are bigger than the max range number in chunks, it is pushed
** back to stack a. If no conditions are met at this point, stack b is rotated.
*/

void	merge_half_to_a(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *chunks)
{
	get_new_chunk_from_median(&chunks, *stack_b, 0);
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

/*
** When sorting stack b, as soon as its number is equal to its sorted
** duplicate version, it is pushed to stack a and the list goes to the
** next number in dup.
** If the numbers are different, the current number in stack b is different
** than the biggest number in stack b and there are other numbers in stack b,
** both stacks are reversely rotated. Else, both rotate at the same time.
** If the stack b number is equal to its maximum, it is pushed back to a (
** numbers will be sorted back from the biggest to the smallest).
** Lastly, if no conditions are met, stack b is rotated.
*/

void	merge_sort_to_a_helper(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *dup)
{
	if ((*stack_b)->number == dup->number)
	{
		pa(stack_a, stack_b);
		dup = dup->next;
		if (ft_lstsize_ps(*stack_b) && (*stack_b)->number != dup->number
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
** This function merges the sorted rest of stack b to stack a.
** First, it sorts stack b in a helper function
** Second, while the last number of stack a is different than the max
** number of the chunk's range, it is rotated in the stack and we get
** a new max number for the range.
** Lastly, we go back to the head of the duplicate stack b.
*/
void	merge_sort_to_a(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks *chunks)
{
	t_stacks	*dup;

	dup = ft_lstdup_ps(*stack_b);
	if (!dup)
		return ;
	ft_stack_sort(&dup);
	while (ft_lstsize_ps(*stack_b))
		merge_sort_to_a_helper(stack_a, stack_b, dup);
	while (ft_stack_last(*stack_a)->number != chunks->next->number)
		ra(stack_a);
	chunks->next->number = get_next_value(*stack_a, &chunks);
	while (dup->previous != NULL)
		dup = dup->previous;
	ft_lstclear_ps(&dup);
}

/*
** The function checks in which index of the sorted duplicate version of
** stack a is to verify if the number is the last of the duplicate. If so,
** it clears aand return, or it gets the next number to become the newer
** maximum index of the chunk.
*/
int	get_next_value(t_stacks *stack_a, t_stacks **chunks)
{
	t_stacks	*dup;
	int			index;
	int			max;

	dup = ft_lstdup_ps(stack_a);
	ft_stack_sort(&dup);
	index = ft_stack_find_index(dup, (*chunks)->next->number);
	max = ft_stack_get_position(dup, index);
	if (max == ft_stack_last(dup)->number)
	{
		ft_lstclear_ps(&dup);
		return (max);
	}
	else
		max = ft_stack_get_position(dup, index + 1);
	ft_lstclear_ps(&dup);
	return (max);
}
