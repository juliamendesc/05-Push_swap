#include "../includes/push_swap.h"

void	swap(t_stacks **stack)
{
	int	temp;

	temp = (*stack)->number;
	(*stack)->number = (*stack)->next->number;
	(*stack)->next->number = temp;
}

void	reverse_rotate(t_stacks **stack)
{
	t_stacks	*tmp;
	t_stacks	*new_head;
	int			size;
	int			i;

	size = ft_lstsize_ps(*stack);
	if (!size || size == 1)
		return ;
	tmp = *stack;
	i = 0;
	while (++i < size - 1)
		tmp = tmp->next;
	new_head = tmp->next;
	tmp->next = NULL;
	new_head->next = *stack;
	*stack = new_head;
}

void	rotate(t_stacks **stack)
{
	t_stacks	*tmp;
	t_stacks	*new_head;

	new_head = (*stack)->next;
	tmp = *stack;
	*stack = new_head;
	tmp->next = NULL;
	ft_lstadd_back_ps(stack, tmp);
}

void	push(t_stacks **src, t_stacks **dest)
{
	t_stacks	*tmp;

	tmp = *src;
	if (!tmp)
		return ;
	*src = tmp->next;
	tmp->next = 0;
	ft_lstadd_front_ps(dest, tmp);
}
