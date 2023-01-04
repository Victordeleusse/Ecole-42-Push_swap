/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:33:56 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/04 09:49:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Operations on stack : extracting the first and the last elem,
// adding an elem at the top or the bottom of a stack */

#include "../pushswap.h"

t_stack_list	*ft_pop_first(t_stack_list **stack)
{
	t_stack_list	*first_elem;
	t_stack_list	*second_elem;

	if (!*stack)
		return (NULL);
	first_elem = *stack;
	second_elem = first_elem->next;
	*stack = second_elem;
	if (!second_elem)
		return (first_elem);
	first_elem->next = NULL;
	second_elem->previous = NULL;
	return (first_elem);
}

t_stack_list	*ft_pop_last(t_stack_list **stack)
{
	t_stack_list	*begin;
	t_stack_list	*last_elem;

	if (!*stack)
		return (NULL);
	if (!(*stack)->next)
		return (*stack);
	begin = *stack;
	while (begin->next->next)
		begin = begin->next;
	last_elem = begin->next;
	begin->next = NULL;
	last_elem->previous = NULL;
	return (last_elem);
}

void	ft_add_first(t_stack_list **stack, t_stack_list *element)
{
	t_stack_list	*first_elem;

	if (!element)
		return ;
	if (*stack == NULL)
	{
		*stack = element;
		return ;
	}
	first_elem = *stack;
	first_elem->previous = element;
	element->next = first_elem;
	*stack = element;
}

void	ft_add_last(t_stack_list **stack, t_stack_list *element)
{
	t_stack_list	*begin;

	if (!element)
		return ;
	if (!*stack)
	{
		*stack = element;
		return ;
	}
	begin = *stack;
	while (begin->next)
		begin = begin->next;
	begin->next = element;
	element->previous = begin;
}
