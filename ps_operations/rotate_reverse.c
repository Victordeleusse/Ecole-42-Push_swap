/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:20:18 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/06 15:59:45 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Rotate and Reverse Rotate rules */

#include "../pushswap.h"

/* le premier element de la pile devient le dernier */

void	ft_rotate_a(t_stack_list **stack_a, int *count)
{
	t_stack_list	*extract;

	if (!*stack_a || (*stack_a)->next == NULL)
		return ;
	extract = ft_pop_first(stack_a);
	ft_add_last(stack_a, extract);
	(*count)++;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack_list **stack_b, int *count)
{
	t_stack_list	*extract;

	if (!*stack_b || (*stack_b)->next == NULL)
		return ;
	extract = ft_pop_first(stack_b);
	ft_add_last(stack_b, extract);
	(*count)++;
	ft_printf("rb\n");
}

void	ft_double_rotate(t_stack_list **stack_a, t_stack_list **stack_b, \
	int *count)
{
	ft_rotate_a(stack_a, count);
	ft_rotate_b(stack_b, count);
	ft_printf("rr\n");
	count--;
}

/* le dernier element de la pile devient le premier */

void	ft_reverse_rotate_a(t_stack_list **stack_a, int *count)
{
	t_stack_list	*extract;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	extract = ft_pop_last(stack_a);
	ft_add_first(stack_a, extract);
	(*count)++;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack_list **stack_b, int *count)
{
	t_stack_list	*extract;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	extract = ft_pop_last(stack_b);
	ft_add_first(stack_b, extract);
	(*count)++;
	ft_printf("rrb\n");
}

void	ft_double_reverse_rotate(t_stack_list **stack_a, \
	t_stack_list **stack_b, int *count)
{
	ft_reverse_rotate_a(stack_a, count);
	ft_reverse_rotate_b(stack_b, count);
	ft_printf("rrr\n");
	count--;
}
