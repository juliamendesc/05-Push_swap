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
int get_min(t_stacks *stack);
int get_max(t_stacks *stack);
void push_min_to_b(t_stacks **stack_a, t_stacks **stack_b);
int range(t_stacks *stack_a, int local_max);
int get_range_pos(t_stacks *stack_a, int chunk_max);
void prepare_to_pb(t_stacks **stack_a, t_stacks **stack_b);
void sort_a_within_range(t_stacks **stack_a, t_stacks **stack_b, int range_pos, int chunk);
void sort_medium(t_stacks **stack_a, t_stacks **stack_b);
int pos_finder(t_stacks *stack, int pos, int small);
void call_ra(t_stacks **stack_a, int pos);
void call_rra(t_stacks **stack_a, int pos);
void call_rb(t_stacks **stack_b, int pos);
void call_rrb(t_stacks **stack_b, int pos);
void decide_ra_or_rra(t_stacks **stack_a, int range_pos);
void decide_rb_or_rrb(t_stacks **stack_b, int range_pos);
int get_b_min_pos(t_stacks *stack_b, int b_minimum);
void sort_b_small_or_big(t_stacks **stack_a, t_stacks **stack_b);
int get_b_to_a_pos(t_stacks **stack_a, t_stacks **stack_b);
void rb_pa(t_stacks **stack_a, t_stacks **stack_b, int pos);
void rrb_pa(t_stacks **stack_a, t_stacks **stack_b, int pos, int len);
void rb_or_rbb_one_hundred(t_stacks **stack_a, t_stacks **stack_b, int len);
void lst_print_norm(char *msg, t_stacks *stack);
void lst_print(char *msg, t_stacks *stack);

#endif
