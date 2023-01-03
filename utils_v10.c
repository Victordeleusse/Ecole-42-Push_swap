/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:20 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/03 14:38:21 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_distance_10(t_stack_list **stack, int size_stack_init)
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
	while (begin->index_sorted > (size_stack_init - 5) && end->index_sorted > (size_stack_init - 5))
	{
		begin = begin->next;
		end = end->previous;
		distance_begining++;
		distance_end--;
	}
	if (begin->index_sorted <= (size_stack_init - 5))
		return (distance_begining);
	else 
		return(distance_end);
}

void	ft_exit_case_10(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int size_stack, int size_stack_init)
{
	int	distance;
	
	distance = ft_distance_10(stack_a, size_stack_init);
	if (distance == 0)
	{
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
	if (distance == 1)
	{
		ft_swap_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
	if (distance == size_stack - 1)
	{
		ft_reverse_rotate_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}	
	if (distance == 2)
	{
		ft_rotate_a(stack_a, count);
		ft_swap_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
	if (distance == size_stack - 2)
	{
		ft_reverse_rotate_a(stack_a, count);
		ft_reverse_rotate_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
	if (distance == 3)
	{
		ft_rotate_a(stack_a, count);
		ft_rotate_a(stack_a, count);
		ft_swap_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
	if (distance == size_stack - 3)
	{
		ft_reverse_rotate_a(stack_a, count);
		ft_reverse_rotate_a(stack_a, count);
		ft_reverse_rotate_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		return ;
	}
}


void	ft_separate_stack(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int size_stack_init)
{
	int				size_stack;
	
	size_stack = ft_get_stack_size(stack_a);
	if (size_stack != 5)
	{
		ft_exit_case_10(stack_a, stack_b, count, size_stack, size_stack_init);
		ft_separate_stack(stack_a, stack_b, count, size_stack_init);
	}
}

int	ft_distance_max_in_b(t_stack_list **stack_b)
{
	int				distance_max;
	int				indice_max;
	t_stack_list	*begin_b;
	
	begin_b = *stack_b;
	indice_max = 0;
	while(begin_b)
	{
		if (begin_b->index_sorted >= indice_max)
			indice_max = begin_b->index_sorted;
		begin_b = begin_b->next;
	}
	distance_max = 0;
	begin_b = *stack_b;
	while(begin_b)
	{
		if (begin_b->index_sorted == indice_max)
			break ;
		begin_b = begin_b->next;
		distance_max++;
	}
	return (distance_max);
}

void ft_restore_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, int *count)
{
	int	distance_max_in_b;
	int	size_stack_b;

	distance_max_in_b = ft_distance_max_in_b(stack_b);
	size_stack_b = ft_get_stack_size(stack_b);
	if (!*stack_b)
		return ;
	if (distance_max_in_b == 0)
	{
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);	
	}
	if (distance_max_in_b == 1)
	{
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);	
	}
	if (distance_max_in_b == 2)
	{
		ft_rotate_b(stack_b, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);	
	}
	if (distance_max_in_b == 3 && size_stack_b == 5)
	{
		ft_reverse_rotate_b(stack_b, count);
		ft_reverse_rotate_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);
	}
	if (distance_max_in_b == 3 && size_stack_b == 4)
	{
		ft_reverse_rotate_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);
	}
	if (distance_max_in_b == 4)
	{
		ft_reverse_rotate_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_restore_b_to_a(stack_b, stack_a, count);
	}
}