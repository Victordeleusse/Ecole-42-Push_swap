/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:32 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/12 18:03:38 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_instruction_bloc(t_instruction_list	*element)
{
	free(element->instruction);
	if (element->next)
	{
		element->next = 0;
		free(element->next);
	}
	free(element);
}

void	ft_free_instruction_list(t_instruction_list *list)
{
	t_instruction_list	*evacuate;

	if (!list)
		return ;
	while (list)
	{
		evacuate = list;
		list = list->next;
		ft_free_instruction_bloc(evacuate);
	}
}

void	ft_free_stack_element(t_stack_list *element)
{
	element->next = 0;
	if (element->next)
	{
		element->next = 0;
		free(element->next);
	}
	if (element->previous)
	{
		element->previous = 0;
		free(element->previous);
	}
	free(element);
}

void	ft_free_stack(t_stack_list **stack)
{
	t_stack_list	*begin;
	t_stack_list	*evacuate;

	if (!stack)
		return ;
	if (!*stack)
	{
		free (stack);
		return ;
	}
	begin = *stack;
	while (begin)
	{
		evacuate = begin;
		begin = begin->next;
		ft_free_stack_element(evacuate);
	}
	free (stack);
}

void	ft_free(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int *tab)
{
	ft_free_instruction_list(instruction_list->next);
	free(instruction_list);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(tab);
}
