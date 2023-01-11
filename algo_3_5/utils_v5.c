/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:53:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_already_sort_5(t_stack_list **stack)
{
	t_stack_list	*begin;

	begin = *stack;
	while (begin->next)
	{
		if (begin->index_sorted > begin->next->index_sorted)
			return (0);
		begin = begin->next;
	}
	return (1);
}

int	ft_get_distance(t_stack_list **stack, int mi)
{
	t_stack_list	*begin;
	t_stack_list	*end;
	int				distance_begining;
	int				distance_end;

	distance_begining = 0;
	distance_end = 0;
	begin = *stack;
	end = *stack;
	while (end->next)
	{
		end = end->next;
		distance_end++;
	}
	while (begin->index_sorted >= mi && end->index_sorted >= mi)
	{
		begin = begin->next;
		end = end->previous;
		distance_begining++;
		distance_end--;
	}
	if (begin->index_sorted < mi)
		return (distance_begining);
	else
		return (distance_end);
}

void	ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, \
	t_instruction_list **instruction_list)
{
	int				size_stack1;
	int				mediane_index;

	if (ft_already_sort_5(stack1))
		return ;
	size_stack1 = ft_get_stack_size(stack1);
	mediane_index = ft_get_mediane_index(stack1);
	if (size_stack1 == 5)
	{
		ft_prepare_stack_4(stack1, stack2, mediane_index, instruction_list);
		ft_prepare_stack_3(stack1, stack2, mediane_index, instruction_list);
		size_stack1 = size_stack1 - 2;
	}
	else if (size_stack1 == 4)
	{
		ft_prepare_stack_3_bis(stack1, stack2, mediane_index, instruction_list);
		size_stack1 = size_stack1 - 1;
	}
	ft_sort_3(stack1, size_stack1, instruction_list);
	ft_prepare_stack_2(stack2, instruction_list);
	ft_push_b_to_a(stack2, stack1, instruction_list);
	ft_push_b_to_a(stack2, stack1, instruction_list);
}
