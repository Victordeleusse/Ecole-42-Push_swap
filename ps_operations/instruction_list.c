/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:51:46 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/12 11:26:31 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_instruction_list	*ft_generate_instruction_element(char *instruction)
{
	t_instruction_list	*instruction_element;

	instruction_element = ft_calloc(sizeof(t_instruction_list), 1);
	if (!instruction_element)
		return (NULL);
	instruction_element->instruction = instruction;
	instruction_element->next = 0;
	return (instruction_element);
}

void	ft_add_instruction_to_list(t_instruction_list **instruction_list, \
			char *str)
{
	t_instruction_list	*element;
	t_instruction_list	*last;

	element = ft_generate_instruction_element(str);
	if (!*instruction_list)
	{
		*instruction_list = element;
		return ;
	}
	last = *instruction_list;
	while (last->next)
		last = last->next;
	(last)->next = element;
}

void	ft_opti_swap(t_instruction_list **instruction_list)
{
	t_instruction_list	*begin;
	t_instruction_list	*evacuate;

	begin = *instruction_list;
	while (begin->next)
	{
		if (begin->instruction[0] == 's' && begin->next->instruction[0] == 's')
		{
			if ((begin->instruction[1] == 'a' && \
			begin->next->instruction[1] == 'b') || \
			(begin->instruction[1] == 'b' && \
			begin->next->instruction[1] == 'a'))
			{
				begin->instruction[1] = 's';
				evacuate = begin->next;
				begin->next = evacuate->next;
				ft_free_instruction_bloc(evacuate);
			}				
		}
		begin = begin->next;
	}
}

void	ft_opti_rotate(t_instruction_list **instruction_list)
{
	t_instruction_list	*begin;
	t_instruction_list	*evacuate;

	begin = *instruction_list;
	while (begin->next)
	{
		if (begin->instruction[0] == 'r' && \
		begin->next->instruction[0] == 'r' && \
		begin->instruction[1] != 'r' && begin->next->instruction[1] != 'r')
		{
			if ((begin->instruction[1] == 'a' && \
			begin->next->instruction[1] == 'b') || \
			(begin->instruction[1] == 'b' && \
			begin->next->instruction[1] == 'a'))
			{
				begin->instruction[1] = 'r';
				evacuate = begin->next;
				begin->next = evacuate->next;
				ft_free_instruction_bloc(evacuate);
			}				
		}
		begin = begin->next;
	}
}

void	ft_opti_reverse_rotate(t_instruction_list **instruction_list)
{
	t_instruction_list	*begin;
	t_instruction_list	*evacuate;

	begin = *instruction_list;
	while (begin->next)
	{
		if (begin->instruction[0] == 'r' && begin->next->instruction[0] == 'r' \
		&& begin->instruction[1] == 'r' && begin->next->instruction[1] == 'r' \
		&& begin->instruction[1] == '\0' && begin->next->instruction[1] == '\0')
		{
			if ((begin->instruction[2] == 'a' && \
			begin->next->instruction[2] == 'b') || \
			(begin->instruction[2] == 'b' && \
			begin->next->instruction[2] == 'a'))
			{
				begin->instruction[2] = 'r';
				evacuate = begin->next;
				begin->next = evacuate->next;
				ft_free_instruction_bloc(evacuate);
			}				
		}
		begin = begin->next;
	}
}
