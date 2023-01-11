/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:33:04 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:38:15 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_exit_dist_3_bis(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
}

void	ft_exit_case_10(t_stack_list **stack_a, t_stack_list **stack_b, \
	int size_stack_init, t_instruction_list **instruction_list)
{
	int	distance;
	int	size_stack;

	size_stack = ft_get_stack_size(stack_a);
	distance = ft_distance_10(stack_a, size_stack_init);
	if (distance == 0)
		ft_push_a_to_b(stack_a, stack_b, instruction_list);
	else if (distance == 1)
		ft_exit_dist_1(stack_a, stack_b, instruction_list);
	else if (distance == size_stack - 1)
		ft_exit_dist_1_bis(stack_a, stack_b, instruction_list);
	else if (distance == 2)
		ft_exit_dist_2(stack_a, stack_b, instruction_list);
	else if (distance == size_stack - 2)
		ft_exit_dist_2_bis(stack_a, stack_b, instruction_list);
	else if (distance == 3)
		ft_exit_dist_3(stack_a, stack_b, instruction_list);
	else if (distance == size_stack - 3)
		ft_exit_dist_3_bis(stack_a, stack_b, instruction_list);
}

void	ft_separate_stack(t_stack_list **stack_a, t_stack_list **stack_b, \
	int size_stack_init, t_instruction_list **instruction_list)
{
	int				size_stack;

	size_stack = ft_get_stack_size(stack_a);
	if (size_stack != 5)
	{
		ft_exit_case_10(stack_a, stack_b, size_stack_init, instruction_list);
		ft_separate_stack(stack_a, stack_b, size_stack_init, instruction_list);
	}
}
