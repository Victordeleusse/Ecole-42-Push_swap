/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:41:13 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/05 17:42:05 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_init_bloc(t_stack_list **stack_a, int size_init)
{
	t_stack_list	*begin_a;
	int				mediane_index;
	
	begin_a = *stack_a;
	mediane_index = size_init / 2;
	// printf("\nINDICE DE LA MEDIANE : %d\n\n", mediane_index);
	while (begin_a)
	{
		if (begin_a->index_sorted > mediane_index && begin_a->index_sorted <= mediane_index + 10)
			begin_a->bloc = 1;
		else if (begin_a->index_sorted > mediane_index + 10 && begin_a->index_sorted <= mediane_index + 20)
			begin_a->bloc = 3;
		else if (begin_a->index_sorted > mediane_index + 20 && begin_a->index_sorted <= mediane_index + 30)
			begin_a->bloc = 5;
		else if (begin_a->index_sorted > mediane_index + 30 && begin_a->index_sorted <= mediane_index + 40)
			begin_a->bloc = 7;
		else if (begin_a->index_sorted > mediane_index + 40 && begin_a->index_sorted <= mediane_index + 50)
			begin_a->bloc = 9;
		else if (begin_a->index_sorted <= mediane_index && begin_a->index_sorted > mediane_index - 10)
			begin_a->bloc = 2;
		else if (begin_a->index_sorted <= mediane_index - 10 && begin_a->index_sorted > mediane_index - 20)
			begin_a->bloc = 4;
		else if (begin_a->index_sorted <= mediane_index - 20 && begin_a->index_sorted > mediane_index - 30)
			begin_a->bloc = 6;
		else if (begin_a->index_sorted <= mediane_index - 30 && begin_a->index_sorted > mediane_index - 40)
			begin_a->bloc = 8;
		else if (begin_a->index_sorted <= mediane_index - 40 && begin_a->index_sorted > mediane_index - 50)
			begin_a->bloc = 10;
		begin_a = begin_a->next;
	}
}
