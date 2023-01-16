/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:41:13 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/16 14:48:42 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_send_a_to_b_from_top_500(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	bool;
	int	distance;
	int	size_stack;
	int	nb_operation;

	bool = 0;
	distance = ft_distance_500(stack_a, &bool);
	size_stack = ft_get_stack_size(stack_a);
	nb_operation = size_stack - distance;
	while (nb_operation)
	{
		ft_reverse_rotate_a(stack_a, instruction_list);
		nb_operation--;
	}
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	if (bool == 2)
		ft_rotate_b(stack_b, instruction_list);
}

void	ft_send_a_to_b_500(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	bool;
	int	distance;
	int	size_stack;
	int	mid_stack;

	bool = 0;
	distance = ft_distance_500(stack_a, &bool);
	size_stack = ft_get_stack_size(stack_a);
	mid_stack = size_stack / 2;
	if (distance > mid_stack)
		ft_send_a_to_b_from_top_500(stack_a, stack_b, instruction_list);
	else
	{
		while (distance)
		{
			ft_rotate_a(stack_a, instruction_list);
			distance--;
		}
		ft_push_a_to_b(stack_a, stack_b, instruction_list);
		if (bool == 2)
			ft_rotate_b(stack_b, instruction_list);
	}
}

void	ft_send_b_to_a_500(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	int	working_bloc;

	working_bloc = (*stack_b)->bloc;
	while (working_bloc > 0)
	{
		while (ft_is_bloc_present(stack_b, working_bloc) == 1)
			ft_send_max_from_b_to_a_500(stack_a, stack_b, \
				working_bloc, instruction_list);
		working_bloc = working_bloc - 2;
	}
	if (working_bloc <= 0 && !(*stack_b))
		return ;
	working_bloc = (*stack_b)->bloc;
	while (working_bloc <= 20)
	{
		while (ft_is_bloc_present(stack_b, working_bloc) == 1)
			ft_send_max_from_b_to_a_500(stack_a, stack_b, \
				working_bloc, instruction_list);
		working_bloc = working_bloc + 2;
	}
}
