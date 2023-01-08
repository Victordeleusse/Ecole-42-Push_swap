/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:51:46 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/08 18:11:38 by vde-leus         ###   ########.fr       */
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
	return(instruction_element);
}

void	ft_add_instruction_to_list(t_instruction_list **instruction_list, char *str)
{
	t_instruction_list	*element;
	
	element = ft_generate_instruction_element(str);
	if (!*instruction_list)
	{
		*instruction_list = element;
		return ;
	}
	(*instruction_list)->next = element;
	*instruction_list = (*instruction_list)->next;
}