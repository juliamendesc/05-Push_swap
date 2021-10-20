#include "./push_swap.h"

void ft_lstclear_ps(t_stacks **lst)
{
	t_stacks *current;
	t_stacks *next;

	if (!lst)
		return;
	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

t_stacks *ft_lstnew_ps(int content)
{
	t_stacks *new;

	new = malloc(sizeof(t_stacks));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	if (new)
	{
		new->number = content;
		new->next = NULL;
	}
	return (new);
}

void ft_lstadd_back_ps(t_stacks **lst, t_stacks *new)
{
	t_stacks *begin;

	if (!*lst)
	{
		(*lst) = new;
		return;
	}
	if (lst && (*lst) && new)
	{
		begin = (*lst);
		if (begin == NULL)
			(*lst) = new;
		else
		{
			while (begin->next)
				begin = begin->next;
			begin->next = new;
		}
	}
}

int ft_lstsize_ps(t_stacks *lst)
{
	int count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// t_stacks *ft_lstgoto_end_ps(t_stacks **lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while ((*lst)->next != NULL)
// 		(*lst) = (*lst)->next;
// 	return (*lst);
// }

void ft_lstadd_front_ps(t_stacks **lst, t_stacks *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
