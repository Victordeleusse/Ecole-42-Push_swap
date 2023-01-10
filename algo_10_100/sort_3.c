/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:22:39 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:22:57 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_sort_3_in_a_100_case_1(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_sort_3_in_a_100_case_2(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_a(stack_a, instruction_list);
}

void	ft_sort_3_in_a_100_case_3(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_swap_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_sort_3_in_a_100_case_4(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	ft_swap_a(stack_a, instruction_list);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}

void	ft_sort_3_in_a_100(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	index_a;
	int	index_b;
	int	index_c;

	index_a = (*stack_a)->index_sorted;
	index_b = (*stack_a)->next->index_sorted;
	index_c = (*stack_a)->next->next->index_sorted;
	if (index_a < index_b && index_b < index_c && index_a < index_c)
		return ;
	else if (index_a < index_b && index_b > index_c && index_a < index_c)
		ft_sort_3_in_a_100_case_1(stack_a, stack_b, instruction_list);
	else if (index_a < index_b && index_b > index_c && index_a > index_c)
		ft_sort_3_in_a_100_case_2(stack_a, stack_b, instruction_list);
	else if (index_a > index_b && index_b < index_c && index_a < index_c)
		ft_swap_a(stack_a, instruction_list);
	else if (index_a > index_b && index_b < index_c && index_a > index_c)
		ft_sort_3_in_a_100_case_3(stack_a, stack_b, instruction_list);
	else if (index_a > index_b && index_b > index_c && index_a > index_c)
		ft_sort_3_in_a_100_case_4(stack_a, stack_b, instruction_list);
}
