#include "./push_swap.h"

void decide_ra_or_rra(t_stacks **stack_a, int range_pos)
{
	int len;

	len = 0;
	len = ft_lstsize_ps(*stack_a);
	if (range_pos < (len / 2))
	{
		while (range_pos != 0)
		{
			ra(stack_a);
			range_pos--;
		}
	}
	if (range_pos >= (len / 2))
	{
		while (range_pos != 0)
		{
			rra(stack_a);
			range_pos--;
		}
	}
}

void decide_rb_or_rrb(t_stacks **stack_b, int range_pos)
{
	int len;

	len = 0;
	len = ft_lstsize_ps(*stack_b);
	if (range_pos < (len / 2))
	{
		while (range_pos != 0)
		{
			rb(stack_b);
			range_pos--;
		}
	}
	if (range_pos >= (len / 2))
	{
		while (range_pos != 0)
		{
			rrb(stack_b);
			range_pos--;
		}
	}
}

int get_b_min_pos(t_stacks *stack_b, int b_minimum)
{
	int pos_num;

	pos_num = 0;
	while (stack_b)
	{
		if (stack_b->number == b_minimum)
			return (pos_num);
		stack_b = stack_b->next;
		pos_num++;
	}
	return (pos_num);
}

void sort_b_small_or_big(t_stacks **stack_a, t_stacks **stack_b)
{
	int b_maximum;
	int b_minimum;
	int b_min_pos;

	b_maximum = get_max(*stack_b);
	b_minimum = get_min(*stack_b);
	b_min_pos = get_b_min_pos(*stack_b, b_minimum);
	if ((*stack_a)->number < b_minimum || (*stack_a)->number > b_maximum)
	{
		decide_rb_or_rrb(stack_b, b_min_pos);
		pb(stack_a, stack_b);
	}
}

int get_b_to_a_pos(t_stacks **stack_a, t_stacks **stack_b)
{
	int pos;
	t_stacks *temp;

	pos = 0;
	temp = *stack_b;
	if (stack_a)
	{
		while (temp)
		{
			pos++;
			if (temp->next != NULL)
			{
				if ((*stack_a)->number > temp->number && (*stack_a)->number < temp->next->number)
					return (pos);
			}
			temp = temp->next;
		}
	}
	return (pos);
}

void rb_pa(t_stacks **stack_a, t_stacks **stack_b, int pos)
{
	while (pos > 0)
	{
		rb(stack_b);
		pos--;
	}
	if (pos == 0)
		pa(stack_a, stack_b);
}

void rrb_pa(t_stacks **stack_a, t_stacks **stack_b, int pos, int len)
{
	int maximum;

	maximum = get_max(*stack_b);
	while (len > pos)
	{
		rrb(stack_b);
		pos++;
	}
	if ((*stack_b)->number == maximum)
		pa(stack_a, stack_b);
}

void rb_or_rbb_one_hundred(t_stacks **stack_a, t_stacks **stack_b, int len)
{
	int half;
	int pos;
	int maximum;

	while (*stack_b)
	{
		len = ft_lstsize_ps(*stack_b);
		half = (len / 2);
		pos = 0;
		maximum = get_max(*stack_b);
		pos = pos_finder(*stack_b, pos, maximum);
		if (pos <= half)
			rb_pa(stack_a, stack_b, pos);
		if (pos > half)
			rrb_pa(stack_a, stack_b, pos, len);
	}
}
