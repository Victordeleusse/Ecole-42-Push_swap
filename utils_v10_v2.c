/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:28:30 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/02 16:42:12 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_distance_multibloc(t_stack_list **stack, int mediane_index, int bloc)
{
	t_stack_list	*begin;
	t_stack_list	*end;
	int				distance_begining;
	int				distance_end;

	distance_begining = 0;
	distance_end = 0;
	begin = *stack;
	end = *stack;
	while (end->next && end->bloc == bloc)
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

int	ft_prepare_stack_4_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance_multibloc(stack1, mediane_index, begin1->bloc);
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
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
	}
	if (distance == 3)
	{
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
		ft_push_a_to_b(stack1, stack2, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
		return (1);
	}
	return (0);	
}

void	ft_prepare_stack_3_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance_multibloc(stack1, mediane_index, begin1->bloc);
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
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
	}
	if (distance == 3)
	{
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
	}
}

void	ft_prepare_stack_3_bis_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int	distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance_multibloc(stack1, mediane_index, begin1->bloc);
	mediane_index = ft_get_mediane_index(stack1) - 1;
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
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
	}
	if (distance == 3)
	{
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
		ft_reverse_rotate_a(stack1, count);
	}
}

void	ft_sort_3_multibloc(t_stack_list **stack_a, int *count, int size_stack_a)
{
	int				pos;

	pos = ft_get_pos_min(stack_a);
	if (pos == 0)
		ft_case_beginning(stack_a, count);
	else if (pos == 2)
		ft_case_end(stack_a, count, size_stack_a);
	else
		ft_case_middle(stack_a, count, size_stack_a);
	return ;
}

void	ft_sort_10(t_stack_list **stack1, t_stack_list **stack2, int *count)
{
	t_stack_list	*begin1;
	t_stack_list	*begin2;
	int				size_stack1;
	int 			mediane_index;
	int				jump;
	
	mediane_index = ft_get_mediane_index(stack1);
	size_stack1 = ft_get_stack_size(stack1);
	if (size_stack1 == 5)
	{
		jump = ft_prepare_stack_4_multibloc(stack1, stack2, count, mediane_index);
		while (jump == 0)
		{
			ft_prepare_stack_3_multibloc(stack1, stack2, count, mediane_index);
			jump++;
		}
		size_stack1 = size_stack1 - 2;
	}
	else if (size_stack1 == 4)
	{
		ft_prepare_stack_3_bis_multibloc(stack1, stack2, count, mediane_index);
		size_stack1 = size_stack1 - 1;
	}
	begin1 = *stack1;
	while (begin1)
		begin1 = begin1->next;
	ft_sort_3_multibloc(stack1, count, 4);
	if (*stack2 && (*stack2)->next)
	{
		begin2 = *stack2;
		if (begin2->index_sorted < begin2->next->index_sorted)
			ft_swap_b(stack2, count);
	}	
	ft_push_b_to_a(stack2, stack1, count);
	ft_push_b_to_a(stack2, stack1, count);
}
