/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_bloc_10_to_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:18:37 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:18:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_get_max_in_bloc_10(t_stack_list **stack, int working_bloc)
{
	t_stack_list	*begin;
	int				index_max;

	begin = *stack;
	index_max = begin->index_sorted;
	while (begin && begin->bloc == working_bloc)
	{
		if (begin->index_sorted > index_max)
			index_max = begin->index_sorted;
		begin = begin->next;
	}
	return (index_max);
}

void	ft_finish_cuting_in_half(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list, \
	int nb_rotate)
{
	while (nb_rotate != 0)
	{
		ft_reverse_rotate_b(stack_b, instruction_list);
		nb_rotate--;
	}
	ft_sort_5_in_full_a(stack_a, stack_b, instruction_list);
	if ((*stack_b))
		ft_sort_5_in_full_b(stack_a, stack_b, instruction_list);
}

void	ft_rotate_5_in_10(t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int *nb_rotate)
{
	ft_rotate_b(stack_b, instruction_list);
	*nb_rotate = *nb_rotate + 1;
}

void	ft_cut_bloc_10_to_5_in_b(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list)
{
	t_stack_list	*begin_b;
	int				working_bloc;
	int				max_bloc;
	int				nb_rotate;
	int				nb_already_pushed;

	nb_already_pushed = 0;
	working_bloc = (*stack_b)->bloc;
	max_bloc = ft_get_max_in_bloc_10(stack_b, working_bloc);
	begin_b = *stack_b;
	nb_rotate = 0;
	while (begin_b && begin_b->bloc == working_bloc && nb_already_pushed < 5)
	{
		if (begin_b->index_sorted > (max_bloc - 5))
		{
			ft_push_b_to_a(stack_b, stack_a, instruction_list);
			nb_already_pushed++;
		}
		else
			ft_rotate_5_in_10(stack_b, instruction_list, &nb_rotate);
		begin_b = *stack_b;
	}
	ft_finish_cuting_in_half(stack_b, stack_a, instruction_list, nb_rotate);
}
