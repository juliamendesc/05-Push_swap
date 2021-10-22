#include "./push_swap.h"

static void print_stacks(int number)
{
	char *char_number;

	char_number = ft_itoa(number);
	printf("%s ", char_number);
	free(char_number);
}

void lst_print(char *msg, t_stacks *stack)
{
	printf("%s", msg);
	if (stack)
	{
		while (stack->next)
		{
			print_stacks(stack->number);
			stack = stack->next;
		}
		print_stacks(stack->number);
		printf("\n");
	}
	else
	{
		ft_putstr_fd("(empty)\n", 1);
	}
}

void lst_print_norm(char *msg, t_stacks *stack)
{
	ft_putstr_fd(msg, 1);
	if (stack)
	{
		while (stack->next)
		{
			print_stacks(stack->number);
			stack = stack->next;
		}
		print_stacks(stack->number);
		write(1, "\n", 1);
	}
	else
	{
		ft_putstr_fd("(empty)\n", 1);
	}
}
