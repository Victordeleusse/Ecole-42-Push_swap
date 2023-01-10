/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_3_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:43:40 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:43:58 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_send_3_exec_5(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_3_exec_6(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_3_exec_global(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	index_a;
	int	index_b;
	int	index_c;

	index_a = (*stack_b)->index_sorted;
	index_b = (*stack_b)->next->index_sorted;
	index_c = (*stack_b)->next->next->index_sorted;
	if (index_a > index_b && index_b > index_c && index_a > index_c)
		ft_send_3_exec_1(stack_a, stack_b, instruction_list);
	else if (index_a > index_b && index_b < index_c && index_a > index_c)
		ft_send_3_exec_2(stack_a, stack_b, instruction_list);
	else if (index_a < index_b && index_b < index_c && index_a < index_c)
		ft_send_3_exec_3(stack_a, stack_b, instruction_list);
	else if (index_a < index_b && index_b > index_c && index_a < index_c)
		ft_send_3_exec_4(stack_a, stack_b, instruction_list);
	else if (index_a < index_b && index_b > index_c && index_a > index_c)
		ft_send_3_exec_5(stack_a, stack_b, instruction_list);
	else if (index_a > index_b && index_b < index_c && index_a < index_c)
		ft_send_3_exec_6(stack_a, stack_b, instruction_list);
}

void	ft_send_3_from_b_in_a_100(t_stack_list **stack_a, \
	t_stack_list **stack_b, int wb, \
	t_instruction_list **instruction_list)
{
	if (!*stack_b || (*stack_b)->bloc != wb)
		return ;
	if (!(*stack_b)->next || (*stack_b)->next->bloc != wb)
	{	
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
		return ;
	}
	if (!(*stack_b)->next->next || (*stack_b)->next->next->bloc != wb)
	{
		ft_send_3_test_1(stack_a, stack_b, instruction_list);
		return ;
	}
	ft_send_3_exec_global(stack_a, stack_b, instruction_list);
}
