/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:46:20 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:43:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_distance_10(t_stack_list **stack, int ssi)
{
	t_stack_list	*begin;
	t_stack_list	*end;
	int				distance_begining;
	int				distance_end;

	distance_begining = 0;
	distance_end = 0;
	begin = *stack;
	end = *stack;
	while (end->next)
	{
		end = end->next;
		distance_end++;
	}
	while (begin->index_sorted > (ssi - 5) && end->index_sorted > (ssi - 5))
	{
		begin = begin->next;
		end = end->previous;
		distance_begining++;
		distance_end--;
	}
	if (begin->index_sorted <= (ssi - 5))
		return (distance_begining);
	else
		return (distance_end);
}

int	ft_distance_max_in_b(t_stack_list **stack_b)
{
	int				distance_max;
	int				indice_max;
	t_stack_list	*begin_b;

	begin_b = *stack_b;
	indice_max = 0;
	while (begin_b)
	{
		if (begin_b->index_sorted >= indice_max)
			indice_max = begin_b->index_sorted;
		begin_b = begin_b->next;
	}
	distance_max = 0;
	begin_b = *stack_b;
	while (begin_b)
	{
		if (begin_b->index_sorted == indice_max)
			break ;
		begin_b = begin_b->next;
		distance_max++;
	}
	return (distance_max);
}
