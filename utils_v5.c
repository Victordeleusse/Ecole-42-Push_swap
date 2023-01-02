/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/02 11:02:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	ft_prepare_stack_4(t_stack_list **stack1, t_stack_list **stack2, int *count)
{
	int	distance;
	int	mediane_index;

	mediane_index = ft_get_mediane_index(stack1);
	distance = ft_get_distance(stack1, mediane_index);
	printf("distance : %d\n", distance);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, count);
	if (distance == 1)
	{
		ft_swap_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
	if (distance == 4)
	{
		ft_reverse_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}	
}

void	ft_prepare_stack_3(t_stack_list **stack1, t_stack_list **stack2, int *count)
{
	int	distance;
	int	mediane_index;

	mediane_index = ft_get_mediane_index(stack1);
	distance = ft_get_distance(stack1, mediane_index);
	printf("distance : %d\n", distance);
	if (distance == 0)
		ft_push_a_to_b(stack1, stack2, count);
	if (distance == 1)
	{
		ft_swap_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
	if (distance == 2)
	{
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
}

void	ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, int *count)
{
	t_stack_list	*begin2;

	ft_prepare_stack_4(stack1, stack2, count);
	ft_prepare_stack_3(stack1, stack2, count);
	ft_sort_3(stack1, count);
	if (*stack2 && (*stack2)->next)
	{
		begin2 = *stack2;
		if (begin2->index_sorted < begin2->next->index_sorted)
			ft_swap_b(stack2, count);
	}	
	ft_push_b_to_a(stack2, stack1, count);
	ft_push_b_to_a(stack2, stack1, count);
}
