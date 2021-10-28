#include "../includes/push_swap.h"

void	sort_big(t_stacks **stack_a, t_stacks **stack_b,
			t_stacks **chunks, int i)
{
	if (ft_lstsize_ps(*chunks) == 1)
	{
		ft_lstclear_ps(chunks);
		return ;
	}
	if (ft_lstsize_ps(*chunks) == 2
		&& count_in_between(*stack_a, *chunks) >= MAX_SIZE)
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
	sort_big(stack_a, stack_b, chunks, ++i);
}
