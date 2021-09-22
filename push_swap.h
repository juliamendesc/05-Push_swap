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
	int							number;
	int							order;
	struct s_stack	*next;
}							t_stack;

void	ft_exit_ps(char *arg, int err);
void	ft_help(void);
int	error_handling(int argc, char **argv);

#endif
