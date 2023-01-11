/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_part1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:27:15 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:27:41 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_exit_dist_1(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_swap_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}

void	ft_exit_dist_1_bis(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}

void	ft_exit_dist_2(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_rotate_a(stack_a, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}

void	ft_exit_dist_2_bis(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}

void	ft_exit_dist_3(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_rotate_a(stack_a, instruction_list);
	ft_rotate_a(stack_a, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}
