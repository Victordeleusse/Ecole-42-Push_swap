/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/08 18:08:14 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_get_distance(t_stack_list **stack, int mediane_index)
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
	while (begin->index_sorted >= mediane_index && end->index_sorted >= mediane_index)
	{
		begin = begin->next;
		end = end->previous;
		distance_begining++;
		distance_end--;
	}
	if (begin->index_sorted < mediane_index)
		return (distance_begining);
	else 
		return(distance_end);
}

void	ft_prepare_stack_4(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index, t_instruction_list **instruction_list)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	if (distance == 1)
	{
		ft_swap_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, count, instruction_list);
		ft_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count, instruction_list);
		ft_reverse_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 4)
	{
		ft_reverse_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}	
}

void	ft_prepare_stack_3(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index, t_instruction_list **instruction_list)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	if (distance == 1)
	{
		ft_swap_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, count, instruction_list);
		ft_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
}

void	ft_prepare_stack_3_bis(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index, t_instruction_list **instruction_list)
{
	int	distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	mediane_index = ft_get_mediane_index(stack1);
	distance = ft_get_distance(stack1, mediane_index);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	if (distance == 1)
	{
		ft_swap_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, count, instruction_list);
		ft_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count, instruction_list);
		ft_push_a_to_b(stack1, stack2, count, instruction_list);
	}
}

void	ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, int *count, t_instruction_list **instruction_list)
{
	t_stack_list	*begin1;
	t_stack_list	*begin2;
	int				size_stack1;
	int 			mediane_index;
	
	begin1 = *stack1;
	if (ft_already_sort_5(stack1))
		return ;
	size_stack1 = ft_get_stack_size(stack1);
	mediane_index = ft_get_mediane_index(stack1);
	if (size_stack1 == 5)
	{
		ft_prepare_stack_4(stack1, stack2, count, mediane_index, instruction_list);
		ft_prepare_stack_3(stack1, stack2, count, mediane_index, instruction_list);
		size_stack1 = size_stack1 - 2;
	}
	else if (size_stack1 == 4)
	{
		ft_prepare_stack_3_bis(stack1, stack2, count, mediane_index, instruction_list);
		size_stack1 = size_stack1 - 1;
	}
	begin1 = *stack1;
	while (begin1)
	{
		begin1 = begin1->next;
	}
	ft_sort_3(stack1, count, size_stack1, instruction_list);
	if (*stack2 && (*stack2)->next)
	{
		begin2 = *stack2;
		if (begin2->index_sorted < begin2->next->index_sorted)
			ft_swap_b(stack2, count, instruction_list);
	}	
	ft_push_b_to_a(stack2, stack1, count, instruction_list);
	ft_push_b_to_a(stack2, stack1, count, instruction_list);
}
