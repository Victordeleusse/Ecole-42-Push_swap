/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:20:18 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/09 16:01:53 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rotate and Reverse Rotate rules */

#include "../pushswap.h"

/* le premier element de la pile devient le dernier */

void	ft_rotate_a(t_stack_list **stack_a, int *count, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*extract;
	char			*instruction;

	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	extract = ft_pop_first(stack_a);
	ft_add_last(stack_a, extract);
	(*count)++;
	instruction[0] = 'r';
	instruction[1] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_rotate_b(t_stack_list **stack_b, int *count, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*extract;
	char			*instruction;

	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	extract = ft_pop_first(stack_b);
	ft_add_last(stack_b, extract);
	(*count)++;
	instruction[0] = 'r';
	instruction[1] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_double_rotate(t_stack_list **stack_a, t_stack_list **stack_b, \
	int *count, t_instruction_list **instruction_list)
{
	ft_rotate_a(stack_a, count, instruction_list);
	ft_rotate_b(stack_b, count, instruction_list);
	count--;
}

/* le dernier element de la pile devient le premier */

void	ft_reverse_rotate_a(t_stack_list **stack_a, int *count, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*extract;
	char			*instruction;

	instruction = ft_calloc(sizeof(char), 4);
	if (!instruction)
		return ;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	extract = ft_pop_last(stack_a);
	ft_add_first(stack_a, extract);
	(*count)++;
	instruction[0] = 'r';
	instruction[1] = 'r';
	instruction[2] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_reverse_rotate_b(t_stack_list **stack_b, int *count, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*extract;
	char			*instruction;

	instruction = ft_calloc(sizeof(char), 4);
	if (!instruction)
		return ;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	extract = ft_pop_last(stack_b);
	ft_add_first(stack_b, extract);
	(*count)++;
	instruction[0] = 'r';
	instruction[1] = 'r';
	instruction[2] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_double_reverse_rotate(t_stack_list **stack_a, \
	t_stack_list **stack_b, int *count, t_instruction_list **instruction_list)
{
	ft_reverse_rotate_a(stack_a, count, instruction_list);
	ft_reverse_rotate_b(stack_b, count, instruction_list);
	count--;
}
