#include "./push_swap.h"

int range(t_stacks *stack_a, int local_max)
{
	while (stack_a)
	{
		if (stack_a->number <= local_max)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int get_range_pos(t_stacks *stack_a, int chunk_max)
{
	int num_pos;
	int i;

	num_pos = 0;
	i = -1;
	while (stack_a)
	{
		i++;
		if (stack_a->number <= chunk_max)
			return (i);
		stack_a = stack_a->next;
	}
	return (i);
}

void prepare_to_pb(t_stacks **stack_a, t_stacks **stack_b)
{
	int pos;
	pos = get_b_to_a_pos(stack_a, stack_b);
	decide_rb_or_rrb(stack_b, pos);
	pb(stack_a, stack_b);
}

void sort_a_within_range(t_stacks **stack_a, t_stacks **stack_b, int range_pos, int chunk)
{
	int len;
	int chunk_max;
	int pos;

	len = ft_lstsize_ps(*stack_a);
	chunk_max = len / 5;
	pos = 0;
	// printf("list len %d\n", len);
	// printf("i original %d\n", i);
	// printf("chegamos aqui\n");
	// printf("chunk max %d\n", chunk_max);
	// printf("range pos 1 %d\n", range_pos);
	while (range(*stack_a, chunk) == 1)
	{
		range_pos = get_range_pos(*stack_a, chunk_max);
		// printf("range pos 1 %d\n", range_pos);
		if ((*stack_a) && (*stack_a)->number > chunk)
			decide_ra_or_rra(stack_a, range_pos);
		if ((*stack_a) && (*stack_a)->number <= chunk)
		{
			if (ft_lstsize_ps(*stack_b) == 1 || (!*stack_b))
				pb(stack_a, stack_b);
		}
		if (ft_lstsize_ps(*stack_b) > 1 && (*stack_a) && (*stack_a)->number <= chunk)
			sort_b_small_or_big(stack_a, stack_b);
		if (ft_lstsize_ps(*stack_b) > 1 && (*stack_a) && (*stack_a)->number <= chunk)
			prepare_to_pb(stack_a, stack_b);
	}
}

void sort_medium(t_stacks **stack_a, t_stacks **stack_b)
{
	int chunk_max;
	int len;
	int i;
	int chunk_len;
	int range_pos;

	i = 0;
	len = ft_lstsize_ps(*stack_a);
	while (*stack_a)
	{
		i++;
		chunk_max = len / 5;
		chunk_len = chunk_max * i;
		range_pos = get_range_pos(*stack_a, chunk_max);
		if (range(*stack_a, chunk_len) == 1)
			sort_a_within_range(stack_a, stack_b, range_pos, chunk_len);
		if (!*stack_a)
			rb_or_rbb_one_hundred(stack_a, stack_b, len);
	}
}
