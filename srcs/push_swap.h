#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int number;
	struct s_stacks *next;
} t_stacks;

void ft_exit_ps(t_stacks **stack_a, t_stacks **stack_b, char *str, int err);
void ft_exit_ps_simple(char *str, int err);
void ft_help(void);
void ft_lstclear_ps(t_stacks **lst);
t_stacks *ft_lstnew_ps(int content);
void ft_lstadd_back_ps(t_stacks **lst, t_stacks *new);
int ft_lstsize_ps(t_stacks *lst);
t_stacks *ft_lstgoto_end_ps(t_stacks **lst);
void ft_lstadd_front_ps(t_stacks **lst, t_stacks *new);
int error_handling(int argc, char **argv);
int is_sorted(t_stacks *stack);
int is_duplicate(int *array, int size);
int duplicate_validation(char **args, int size);
void create_stacks(t_stacks **stack_a, t_stacks **stack_b, int argc, char **argv);
void swap(t_stacks **stack);
void rotate(t_stacks **stack);
void reverse_rotate(t_stacks **stack);
void push(t_stacks **src, t_stacks **dest);
void ra(t_stacks **stack_a);
void rb(t_stacks **stack_b);
void rr(t_stacks **stack_a, t_stacks **stack_b);
void sa(t_stacks **stack_a);
void sb(t_stacks **stack_b);
void ss(t_stacks **stack_a, t_stacks **stack_b);
void rra(t_stacks **stack_a);
void rrb(t_stacks **stack_b);
void rrr(t_stacks **stack_a, t_stacks **stack_b);
void pa(t_stacks **stack_a, t_stacks **stack_b);
void pb(t_stacks **stack_a, t_stacks **stack_b);
void sort_three_to_five(t_stacks **stack_a, t_stacks **stack_b);
void sort_three(t_stacks **src);
void sort_four_five(t_stacks **stack_a, t_stacks **stack_b);
// void sort_five(t_stacks **stack_a, t_stacks **stack_b);
int get_min(t_stacks *stack);
int get_max(t_stacks *stack);
void push_min_to_b(t_stacks **stack_a, t_stacks **stack_b);

#endif
