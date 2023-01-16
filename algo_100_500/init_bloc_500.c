/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bloc_500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:44:23 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/16 15:03:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_start_impair(t_stack_list *begin_a, \
	int mediane_index, int size_init)
{
	int				starting_bloc_impair;

	starting_bloc_impair = 1;
	while (mediane_index < (size_init + 1))
	{
		if (begin_a->index_sorted > mediane_index && \
				begin_a->index_sorted <= mediane_index + 25)
		{
			begin_a->bloc = starting_bloc_impair;
			break ;
		}
		else
		{
			mediane_index = mediane_index + 25;
			starting_bloc_impair = starting_bloc_impair + 2;
		}
	}
}

void	ft_start_pair(t_stack_list *begin_a, \
	int mediane_index)
{
	int				starting_bloc_pair;

	starting_bloc_pair = 2;
	while (mediane_index >= 0)
	{
		if (begin_a->index_sorted <= mediane_index && \
				begin_a->index_sorted > mediane_index - 25)
		{
			begin_a->bloc = starting_bloc_pair;
			break ;
		}
		else
		{
			mediane_index = mediane_index - 25;
			starting_bloc_pair = starting_bloc_pair + 2;
		}
	}	
}

void	ft_init_bloc_500(t_stack_list **stack_a, int size_init)
{
	t_stack_list	*begin_a;
	int				mediane_index;

	begin_a = *stack_a;
	while (begin_a)
	{
		mediane_index = size_init / 2;
		if (begin_a->index_sorted > mediane_index)
			ft_start_impair(begin_a, mediane_index, size_init);
		else
			ft_start_pair(begin_a, mediane_index);
		begin_a = begin_a->next;
	}
}

int	ft_is_bloc_present_500(t_stack_list **stack_a, int bloc_searched)
{
	t_stack_list	*begin_a;

	begin_a = *stack_a;
	while (begin_a)
	{
		if (begin_a->bloc == bloc_searched)
			return (1);
		begin_a = begin_a->next;
	}
	return (0);
}
