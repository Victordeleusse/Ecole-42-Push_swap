/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:07:28 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:46:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La mediane est la MEDIANE BASSE : 7 pour 14 elements (vs. 8) */

#include "../pushswap.h"

void	ft_sort_5_condition(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int working_bloc)
{
	int				nb_rotate;
	int				i;
	int				max_bloc;

	nb_rotate = 0;
	i = 0;
	max_bloc = ft_get_max_in_bloc_10(stack_b, working_bloc);
	while ((*stack_b)->bloc == working_bloc && i < 5)
	{
		if ((*stack_b)->index_sorted > (max_bloc - 2))
			ft_push_b_to_a(stack_b, stack_a, instruction_list);
		else
		{
			ft_rotate_b(stack_b, instruction_list);
			nb_rotate++;
		}	
		i++;
	}
	while (nb_rotate != 0)
	{
		ft_reverse_rotate_b(stack_b, instruction_list);
		nb_rotate--;
	}
}

void	ft_sort_5_in_full_b(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*begin_a;
	int				working_bloc;
	int				max_bloc;

	working_bloc = (*stack_b)->bloc;
	max_bloc = ft_get_max_in_bloc_10(stack_b, working_bloc);
	if (ft_get_stack_size(stack_b) > 3)
		ft_sort_5_condition(stack_a, stack_b, instruction_list, working_bloc);
	begin_a = *stack_a;
	if (begin_a->index_sorted > begin_a->next->index_sorted)
		ft_swap_a(stack_a, instruction_list);
	ft_send_3_from_b_in_a_100(stack_a, stack_b, working_bloc, instruction_list);
}
