/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:24:45 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:25:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_sort_3_in_full_a(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	t_stack_list	*begin_a;
	int				working_bloc;
	int				taille;

	working_bloc = (*stack_a)->bloc;
	begin_a = *stack_a;
	taille = 0;
	while (begin_a && begin_a->bloc == working_bloc)
	{
		taille++;
		begin_a = begin_a->next;
	}
	if (taille == 0 || taille == 1)
		return ;
	else if (taille == 2)
	{
		begin_a = *stack_a;
		if (begin_a->index_sorted > begin_a->next->index_sorted)
			ft_swap_a(stack_a, instruction_list);
	}
	else if (taille == 3)
		ft_sort_3_in_a_100(stack_a, stack_b, instruction_list);
}

void	ft_sort_5_in_big_5(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int working_bloc)
{
	int				max_bloc;
	int				nb_rotate;
	int				i;

	nb_rotate = 0;
	max_bloc = ft_get_max_in_bloc_10(stack_a, working_bloc);
	i = 0;
	while ((*stack_a)->bloc == working_bloc && i < 5)
	{
		if ((*stack_a)->index_sorted < (max_bloc - 2))
			ft_push_a_to_b(stack_a, stack_b, instruction_list);
		else
		{
			ft_rotate_a(stack_a, instruction_list);
			nb_rotate++;
		}	
		i++;
	}
	while (nb_rotate != 0)
	{
		ft_reverse_rotate_a(stack_a, instruction_list);
		nb_rotate--;
	}
}

void	ft_sort_5_in_full_a(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	t_stack_list	*begin_b;
	int				working_bloc;

	working_bloc = (*stack_a)->bloc;
	if (ft_get_stack_size(stack_a) > 3)
		ft_sort_5_in_big_5(stack_a, stack_b, instruction_list, working_bloc);
	begin_b = *stack_b;
	if (begin_b && begin_b->next && \
		begin_b->index_sorted < begin_b->next->index_sorted)
		ft_swap_b(stack_b, instruction_list);
	ft_sort_3_in_full_a(stack_a, stack_b, instruction_list);
	if ((*stack_b) && (*stack_b)->bloc == working_bloc)
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
	if ((*stack_b) && (*stack_b)->bloc == working_bloc)
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
}
