/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:53:56 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/08 17:57:39 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap and Push rules */

#include "../pushswap.h"

/* inversion du premier et du second element de la pile */

void	ft_swap_a(t_stack_list **stack, int *count, t_instruction_list **instruction_list)
{
	t_stack_list	*first;
	t_stack_list	*second;
	char			*instruction;
	
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
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
	(*count)++;
	// ft_printf("sa\n");
	instruction[0] = 's';
	instruction[1] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_swap_b(t_stack_list **stack, int *count, t_instruction_list **instruction_list)
{
	t_stack_list	*first;
	t_stack_list	*second;
	char			*instruction;
	
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
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
	(*count)++;
	// ft_printf("sb\n");
	instruction[0] = 's';
	instruction[1] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_double_swap(t_stack_list **stack1, t_stack_list **stack2, int *count, t_instruction_list **instruction_list)
{
	ft_swap_a(stack1, count, instruction_list);
	ft_swap_b(stack2, count, instruction_list);
	count--;
}

/* premier element de 1 vers haut de la pile 2 */

void	ft_push_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, \
	int *count, t_instruction_list **instruction_list)
{
	t_stack_list	*elem_top;
	char			*instruction;
	
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	if (!*stack_a)
		return ;
	elem_top = ft_pop_first(stack_a);
	ft_add_first(stack_b, elem_top);
	(*count)++;
	// ft_printf("pb\n");
	instruction[0] = 'p';
	instruction[1] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_push_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, \
	int *count, t_instruction_list **instruction_list)
{
	t_stack_list	*elem_top;
	char			*instruction;
	
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	if (!*stack_b)
		return ;
	elem_top = ft_pop_first(stack_b);
	ft_add_first(stack_a, elem_top);
	(*count)++;
	// ft_printf("pa\n");
	instruction[0] = 'p';
	instruction[1] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}
