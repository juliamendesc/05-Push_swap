#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <ctype.h>
# include <stdio.h>
# include "./libft/includes/libft.h"

typedef struct s_stack
{
	int	numbers_a[500];
}				t_stack;

void	ft_exit_ps(char *arg, int err);
void	ft_help(void);
int	error_handling(int argc, char **argv);
void	ft_fill_stack_a(int argc, char **argv, t_stack *stack);
int	ft_A_is_sorted(int argc, t_stack *stack);

#endif
