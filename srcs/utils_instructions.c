/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:47:55 by julcarva          #+#    #+#             */
/*   Updated: 2021/11/13 18:47:58 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_help(void)
{
	ft_putstr_fd("Push_Swap: How to ...\n", 1);
	ft_putstr_fd("To run the program, please use...\n", 1);
	ft_putstr_fd("./push_swap \"Number sequence\"\n", 1);
}

void	ft_exit_ps(t_stacks **stack_a, t_stacks **stack_b, char *str, int err)
{
	if (stack_a)
		ft_lstclear_ps(stack_a);
	if (stack_b)
		ft_lstclear_ps(stack_b);
	if (err == 1)
		ft_putstr_fd(str, 2);
	exit(err);
}

void	ft_exit_ps_simple(char *str, int err)
{
	if (err == -1)
		ft_putstr_fd(str, 2);
	exit(err);
}
