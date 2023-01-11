/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:53:30 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:54:00 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_prepare_stack_4(t_stack_list **stack1, t_stack_list **stack2, \
	int mediane_index, t_instruction_list **instruction_list)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
	{
		ft_push_a_to_b(stack1, stack2, instruction_list);
		return ;
	}
	if (distance == 1)
		ft_swap_a(stack1, instruction_list);
	if (distance == 2)
	{
		ft_rotate_a(stack1, instruction_list);
		ft_rotate_a(stack1, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, instruction_list);
		ft_reverse_rotate_a(stack1, instruction_list);
	}
	if (distance == 4)
		ft_reverse_rotate_a(stack1, instruction_list);
	ft_push_a_to_b(stack1, stack2, instruction_list);
}

void	ft_prepare_stack_3(t_stack_list **stack1, t_stack_list **stack2, \
	int mediane_index, t_instruction_list **instruction_list)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, instruction_list);
	if (distance == 1)
	{
		ft_swap_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, instruction_list);
		ft_rotate_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
}

void	ft_prepare_stack_3_bis(t_stack_list **stack1, t_stack_list **stack2, \
	int mediane_index, t_instruction_list **instruction_list)
{
	int	distance;

	mediane_index = ft_get_mediane_index(stack1);
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, instruction_list);
	if (distance == 1)
	{
		ft_swap_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, instruction_list);
		ft_rotate_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, instruction_list);
		ft_push_a_to_b(stack1, stack2, instruction_list);
	}
}

void	ft_prepare_stack_2(t_stack_list **stack2, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*begin2;

	if (*stack2 && (*stack2)->next)
	{
		begin2 = *stack2;
		if (begin2->index_sorted < begin2->next->index_sorted)
			ft_swap_b(stack2, instruction_list);
	}
}
