/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:48:16 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/27 18:59:25 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack_list	*ft_get_last_stack(t_stack_list **stack)
{
	t_stack_list	*last_of_stack;

	last_of_stack = *stack;
	while (last_of_stack->next)
	{
		last_of_stack = last_of_stack->next;
	}
	return (last_of_stack);
}

void	ft_get_ready(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	t_stack_list	*begin_a;
	t_stack_list	*last_a;

	
}
