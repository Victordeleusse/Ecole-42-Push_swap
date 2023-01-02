/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:20 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/02 19:19:52 by vde-leus         ###   ########.fr       */
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
	// printf("distance : %d\n", distance);
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
	// t_stack_list	*begin_a;	
	
	size_stack = ft_get_stack_size(stack_a);
	if (size_stack != 5)
	{
		// printf("\n\nEXIT\n");
		ft_exit_case_10(stack_a, stack_b, count, size_stack, size_stack_init);
		// begin_a = *stack_a;
		// while (begin_a)
		// {
		// 	printf("data : %d\n", begin_a->data);
		// 	printf("indice : %d\n", begin_a->index_sorted);
		// //	printf("bloc : %d\n\n", begin_a->bloc);
		// 	begin_a = begin_a->next;
		// }
		ft_separate_stack(stack_a, stack_b, count, size_stack_init);
	}
}