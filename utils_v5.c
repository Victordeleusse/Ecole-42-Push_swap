/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/27 18:14:50 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Positionnement de la mediane hors du rang 0 ou 1 de mon stack */

// void	ft_get_stack_ready(t_stack_list **stack_a, t_stack_list **stack_b, \
// 	int *count)
// {
// 	t_stack_list	*begin_a;
// 	t_stack_list	*last_a;
// 	int				delta;

// 	begin_a = *stack_a;
// 	if (begin_a->index_sorted == 2)
// 		ft_rotate_a(stack_a, count);
// 	else if (begin_a->next->index_sorted == 2)
// 		ft_reverse_rotate_a(stack_a, count);
// 	begin_a = *stack_a;
// 	delta = begin_a->index_sorted - begin_a->next->index_sorted;
// 	if (abs(delta) != 1 || abs(delta) != 4)
// 	{	
// 		last_a = *stack_a;
// 		while (last_a->next)
// 			last_a = last_a->next;
// 		ft_swap_a(stack_a, count);

// 		ft_rotate_a(stack_a, count);
// 	}
// 	else
// 	{
// 		ft_push_a_to_b(stack_a, count);
// 		ft_push_a_to_b(stack_a, count);
// 	}
// }
