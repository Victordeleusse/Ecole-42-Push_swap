/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:20:18 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/26 15:00:31 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rotate and Reverse Rotate rules */

#include "pushswap.h"

/* le premier element de la pile devient le dernier */

void	ft_rotate(t_stack_list **stack, int *count)
{
	t_stack_list	*extract;

	if (!*stack || (*stack)->next == NULL)
		return ;
	extract = ft_pop_first(stack);
	ft_add_last(stack, extract);
	(*count)++;
}

void	ft_double_rotate(t_stack_list **stack1, t_stack_list **stack2, \
	int *count)
{
	ft_rotate(stack1, count);
	ft_rotate(stack2, count);
}

/* le dernier element de la pile devient le premier */

void	ft_reverse_rotate(t_stack_list **stack, int *count)
{
	t_stack_list	*extract;

	if (!*stack || !(*stack)->next)
		return ;
	extract = ft_pop_last(stack);
	ft_add_first(stack, extract);
	(*count)++;
}

void	ft_double_reverse_rotate(t_stack_list **stack1, t_stack_list **stack2, \
	int *count)
{
	ft_reverse_rotate(stack1, count);
	ft_reverse_rotate(stack2, count);
}
