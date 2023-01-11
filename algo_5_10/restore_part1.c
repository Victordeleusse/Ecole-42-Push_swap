/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:38:52 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:39:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_restore_dist_0(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_restore_dist_1(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_restore_dist_2(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_rotate_b(stack_b, instruction_list);
	ft_swap_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_restore_dist_3(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_b(stack_b, instruction_list);
	ft_reverse_rotate_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_restore_dist_4(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}
