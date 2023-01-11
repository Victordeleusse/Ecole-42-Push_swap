/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:31:21 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:57:08 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_pos_min(t_stack_list **stack_a)
{
	t_stack_list	*min_stack;
	t_stack_list	*begin_stack;
	int				pos_min;
	int				k;

	pos_min = 0;
	k = 0;
	if (!*stack_a)
		return (0);
	min_stack = *stack_a;
	begin_stack = *stack_a;
	if (!min_stack->next)
		return (0);
	while (begin_stack)
	{
		if (min_stack->index_sorted > begin_stack->index_sorted)
		{
			min_stack = begin_stack;
			pos_min = k;
		}
		begin_stack = begin_stack->next;
		k++;
	}
	return (pos_min);
}

void	ft_case_beginning(t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*begin;

	begin = *stack_a;
	if (begin->next->index_sorted > begin->next->next->index_sorted)
	{
		ft_swap_a(stack_a, instruction_list);
		ft_rotate_a(stack_a, instruction_list);
	}
	return ;
}

void	ft_case_end(t_stack_list **stack_a, \
	int size_stack_a, t_instruction_list **instruction_list)
{
	t_stack_list	*begin;

	begin = *stack_a;
	if (size_stack_a == 3)
	{
		if (begin->index_sorted > begin->next->index_sorted)
			ft_swap_a(stack_a, instruction_list);
		ft_reverse_rotate_a(stack_a, instruction_list);
	}
	else
	{
		if (begin->index_sorted > begin->next->index_sorted)
			ft_swap_a(stack_a, instruction_list);
		ft_rotate_a(stack_a, instruction_list);
		ft_swap_a(stack_a, instruction_list);
		ft_reverse_rotate_a(stack_a, instruction_list);
		ft_swap_a(stack_a, instruction_list);
	}
}

void	ft_case_middle(t_stack_list **stack_a, \
	int size_stack_a, t_instruction_list **instruction_list)
{
	t_stack_list	*begin;

	begin = *stack_a;
	if (size_stack_a == 3)
	{
		if (begin->index_sorted < begin->next->next->index_sorted)
			ft_swap_a(stack_a, instruction_list);
		else
			ft_rotate_a(stack_a, instruction_list);
	}
	else
	{
		if (begin->index_sorted < begin->next->next->index_sorted)
			ft_swap_a(stack_a, instruction_list);
		else
		{
			ft_swap_a(stack_a, instruction_list);
			ft_rotate_a(stack_a, instruction_list);
			ft_swap_a(stack_a, instruction_list);
			ft_reverse_rotate_a(stack_a, instruction_list);
		}
	}
}

void	ft_sort_3(t_stack_list **stack_a, \
	int size_stack_a, t_instruction_list **instruction_list)
{
	int				pos;

	pos = ft_get_pos_min(stack_a);
	if (pos == 0)
		ft_case_beginning(stack_a, instruction_list);
	else if (pos == 2)
		ft_case_end(stack_a, size_stack_a, instruction_list);
	else
		ft_case_middle(stack_a, size_stack_a, instruction_list);
	return ;
}
