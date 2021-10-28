#include "../includes/push_swap.h"

int	is_sorted(t_stacks *stack)
{
	t_stacks	*current;

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

int	get_min(t_stacks *stack)
{
	t_stacks	*current;
	int			trigger;
	int			min;

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

int	get_max(t_stacks *stack)
{
	t_stacks	*current;
	int			trigger;
	int			max;

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

int	pos_finder(t_stacks *stack, int pos, int small)
{
	int	i;

	i = -1;
	while (stack)
	{
		i++;
		if (small == stack->number)
			pos = i;
		stack = stack->next;
	}
	return (pos);
}
