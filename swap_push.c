/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:53:56 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/23 11:17:08 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap and Push rules */

#include "pushswap.h"

/* inversion du premier et du second element de la pile */

void	ft_swap(t_stack_list **stack)
{
	t_stack_list	*first;
	t_stack_list	*second;

	if (!*stack)
		return ;
	first = *stack;
	if (!(*stack)->next)
		return ;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = 0;
	*stack = second;
}

void	ft_double_swap(t_stack_list **stack1, t_stack_list **stack2)
{
	ft_swap(stack1);
	ft_swap(stack2);
}

/* premier element de 1 vers haut de la pile 2 */

void	ft_push(t_stack_list **stack1, t_stack_list **stack2)
{
	t_stack_list	*elem_top;

	if (!*stack1)
		return ;
	elem_top = ft_pop_first(stack1);
	ft_add_first(stack2, elem_top);
}

