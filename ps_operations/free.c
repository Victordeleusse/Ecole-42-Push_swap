/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:03:32 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/09 17:38:47 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_instruction_bloc(t_instruction_list	*element)
{
	free(element->instruction);
	// printf("ok");
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
	int					i;

	i = 0;
	if (!list)
		return ;
	while (list)
	{
		evacuate = list;
		printf("instruction : %s\n", evacuate->instruction);
		list = list->next;
		i++;
		printf("free : %d\n", i);
		free(evacuate->instruction);
		if (evacuate->next)
		{
			evacuate->next = 0;
			free(evacuate->next);
		}
		free(evacuate);
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

	if (!*stack)
		return ;
	begin = *stack;
	while (begin)
	{
		evacuate = begin;
		begin = begin->next;
		ft_free_stack_element(evacuate);
	}
	free (stack);
}
