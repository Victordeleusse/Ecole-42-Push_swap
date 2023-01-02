/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/02 18:19:24 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_already_sort_5(t_stack_list **stack, int bloc)
{
	t_stack_list	*begin;

	begin = *stack;
	while (begin->next && begin->bloc == bloc)
	{
		// printf("indice : %d vs. indice suivant : %d\n", begin->index_sorted, begin->next->index_sorted);
		if (begin->index_sorted > begin->next->index_sorted)
			return (0);
		begin = begin->next;
		// printf("indice : %d et bloc : %d\n", begin->index_sorted, begin->bloc);
	}
	return (1);
}

int	ft_get_distance(t_stack_list **stack, int mediane_index, int bloc)
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

void	ft_prepare_stack_4(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index, begin1->bloc);
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

void	ft_prepare_stack_3(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int				distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index, begin1->bloc);
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

void	ft_prepare_stack_3_bis(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index)
{
	int	distance;
	t_stack_list	*begin1;

	begin1 = *stack1;
	distance = ft_get_distance(stack1, mediane_index, begin1->bloc);
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
	}
	if (distance == 3)
	{
		ft_reverse_rotate_a(stack1, count);
		ft_push_a_to_b(stack1, stack2, count);
	}
}

void	ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, int *count)
{
	t_stack_list	*begin1;
	t_stack_list	*begin2;
	int				size_stack1;
	int 			mediane_index;
	
	begin1 = *stack1;
	mediane_index = ft_get_mediane_index(stack1);
	size_stack1 = ft_get_stack_size(stack1);
	if (size_stack1 == 5)
	{
		ft_prepare_stack_4(stack1, stack2, count, mediane_index);
		ft_prepare_stack_3(stack1, stack2, count, mediane_index);
		size_stack1 = size_stack1 - 2;
	}
	else if (size_stack1 == 4)
	{
		ft_prepare_stack_3_bis(stack1, stack2, count, mediane_index);
		size_stack1 = size_stack1 - 1;
	}
	begin1 = *stack1;
	while (begin1)
	{
		begin1 = begin1->next;
	}
	ft_sort_3(stack1, count, size_stack1);
	if (*stack2 && (*stack2)->next)
	{
		begin2 = *stack2;
		if (begin2->index_sorted < begin2->next->index_sorted)
			ft_swap_b(stack2, count);
	}	
	ft_push_b_to_a(stack2, stack1, count);
	ft_push_b_to_a(stack2, stack1, count);
}
