/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_3_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:31:05 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:32:59 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_send_3_test_1(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	index_a;
	int	index_b;

	index_a = (*stack_b)->index_sorted;
	index_b = (*stack_b)->next->index_sorted;
	if (index_a > index_b)
	{
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
	}
	else
	{
		ft_swap_b(stack_b, instruction_list);
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
	}
}

void	ft_send_3_exec_1(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_3_exec_2(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_3_exec_3(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_3_exec_4(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}
