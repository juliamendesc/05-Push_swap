#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>
#include "../libft/includes/libft.h"

#ifndef MAX_SIZE
#define MAX_SIZE 20
#endif

/*
**	Error Handling and Instructions
*/

void ft_exit_ps(t_stacks **stack_a, t_stacks **stack_b, char *str, int err);
void ft_exit_ps_simple(char *str, int err);
void ft_help(void);
int error_handling(int argc, char **argv);
int is_sorted(t_stacks *stack);
int is_duplicate(int *array, int size);
int duplicate_validation(char **args, int size);

/*
**	Operations
*/

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

/*
**	Sorting
*/

void sort_three_to_five(t_stacks **stack_a, t_stacks **stack_b);
void sort_three(t_stacks **src);
void sort_four_five(t_stacks **stack_a, t_stacks **stack_b);
void sort_big(t_stacks **stack_a, t_stacks **stack_b);

/*
**	Utils
*/

int get_min(t_stacks *stack);
int get_max(t_stacks *stack);
int count_middle(t_stacks *stack_a, t_stacks *chunks);
int get_next_value(t_stacks *stack_a, t_stacks **limits);
int get_hold_first(t_stacks *stack_a, t_stacks *chunks);
void get_new_chunk(t_stacks **chunks, t_stacks *stack_a, int status);
void sorting_chunks(t_stacks **stack_a, t_stacks **stack_b, t_stacks **chunks, int i);
void push_min_to_b(t_stacks **stack_a, t_stacks **stack_b);
void split_a_to_b(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks);
void rotate_until_sorted(t_stacks **stack_a, t_stacks *chunks);
void merge_sort_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks);
void merge_half_to_a(t_stacks **stack_a, t_stacks **stack_b, t_stacks *chunks);
int get_pivot(t_stacks *stack);
void sort_low_efficient(t_stacks *sorted);
int divide_stack_b(t_stacks **stack_a, t_stacks **stack_b);
int divide_stack(t_stacks **src, t_stacks **dest,
								 void (*p)(t_stacks **, t_stacks **), void (*r)(t_stacks **), int pivot);
int smaller_equal(t_stacks *src, int pivot);
void algorithm(t_stacks **stack_a, t_stacks **stack_b);
t_stacks *ft_lstlast_ps(t_stacks *lst);
int is_all_big_equal_than(t_stacks *stack, int number);
void rotate_top(t_stacks **stack, int number,
								void (*r)(t_stacks **), void (*rr)(t_stacks **));

#endif
