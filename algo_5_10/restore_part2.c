/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:42:50 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:43:13 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_restore_dist_5(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	ft_reverse_rotate_b(stack_b, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_restore_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_restore_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	int	distance_max_in_b;
	int	size_stack_b;

	distance_max_in_b = ft_distance_max_in_b(stack_b);
	size_stack_b = ft_get_stack_size(stack_b);
	if (!*stack_b)
		return ;
	if (distance_max_in_b == 0)
		ft_restore_dist_0(stack_b, stack_a, instruction_list);
	else if (distance_max_in_b == 1)
		ft_restore_dist_1(stack_b, stack_a, instruction_list);
	else if (distance_max_in_b == 2)
		ft_restore_dist_2(stack_b, stack_a, instruction_list);
	else if (distance_max_in_b == 3 && size_stack_b == 5)
		ft_restore_dist_3(stack_b, stack_a, instruction_list);
	else if (distance_max_in_b == 3 && size_stack_b == 4)
		ft_restore_dist_4(stack_b, stack_a, instruction_list);
	else if (distance_max_in_b == 4)
		ft_restore_dist_5(stack_b, stack_a, instruction_list);
}
