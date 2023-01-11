/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_send_max_500.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:53:41 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 10:54:30 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_get_max_in_bloc_25(t_stack_list **stack, int working_bloc)
{
	t_stack_list	*begin;
	int				index_max;

	begin = *stack;
	index_max = 0;
	while (begin)
	{
		if (begin->index_sorted > index_max && begin->bloc == working_bloc)
			index_max = begin->index_sorted;
		begin = begin->next;
	}
	return (index_max);
}

void	ft_send_max_part_sup(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int *distance)
{
	while (*distance)
	{
		ft_rotate_b(stack_b, instruction_list);
		(*distance) = *distance - 1;
	}
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_max_part_inf(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int *distance)
{
	int				size_stack;

	size_stack = ft_get_stack_size(stack_b);
	*distance = size_stack - *distance;
	while (*distance)
	{
		ft_reverse_rotate_b(stack_b, instruction_list);
		(*distance) = *distance - 1;
	}
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_send_max_in_bloc_25_from_b_to_a(t_stack_list **stack_a, \
	t_stack_list **stack_b, int index_max, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*begin_b;
	int				size_stack;
	int				distance;

	size_stack = ft_get_stack_size(stack_b);
	distance = 0;
	begin_b = *stack_b;
	while (begin_b && begin_b->index_sorted != index_max)
	{
		distance++;
		begin_b = begin_b->next;
	}
	if (distance <= 12 || (distance > 12 && distance < 25 && size_stack > 25))
		ft_send_max_part_sup(stack_a, stack_b, instruction_list, &distance);
	else if ((distance > 12 && distance < 25 && size_stack <= 25) || \
				distance >= 25)
		ft_send_max_part_inf(stack_a, stack_b, instruction_list, &distance);
}

void	ft_send_max_from_b_to_a_500(t_stack_list **stack_a, \
	t_stack_list **stack_b, int working_bloc, t_instruction_list **instruction_list)
{
	int	index_max;

	index_max = ft_get_max_in_bloc_25(stack_b, working_bloc);
	ft_send_max_in_bloc_25_from_b_to_a(stack_a, stack_b, \
		index_max, instruction_list);
}