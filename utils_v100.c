/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:07:28 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/03 18:03:36 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* La mediane est la MEDIANE BASSE : 7 pour 14 elements (vs. 8) */

#include "pushswap.h"

void	ft_init_bloc(t_stack_list **stack_a, int size_init)
{
	t_stack_list	*begin_a;
	int				mediane_index;
	
	begin_a = *stack_a;
	mediane_index = size_init / 2;
	printf("\nINDICE DE LA MEDIANE : %d\n\n", mediane_index);
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

int	ft_is_bloc_present(t_stack_list **stack_a, int bloc_searched)
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

int	ft_distance_min_impair(t_stack_list **stack_a)
{
	int				bloc_impair;
	int				dist_begin_impair;
	int				dist_end_impair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;
	
	bloc_impair = 1;
	while (ft_is_bloc_present(stack_a, bloc_impair) == 0 && bloc_impair < 12)
		bloc_impair = bloc_impair + 2;
	if (bloc_impair == 11)
		return (-1);
	dist_begin_impair = 0;
	dist_end_impair = 0;
	begin_a = *stack_a;
	end_a = *stack_a;
	while (end_a->next)
	{
		dist_end_impair++;
		end_a = end_a->next;
	}
	while (end_a->bloc != bloc_impair && begin_a->bloc != bloc_impair)
	{
		dist_begin_impair++;
		begin_a = begin_a->next;
		dist_end_impair--;
		end_a = end_a->previous;
	}
	if (begin_a->bloc == bloc_impair)
		return (dist_begin_impair);
	else
		return (dist_end_impair);	
}

int	ft_distance_min_pair(t_stack_list **stack_a)
{
	int				bloc_pair;
	int				dist_begin_pair;
	int				dist_end_pair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;
	
	bloc_pair = 2;
	while (ft_is_bloc_present(stack_a, bloc_pair) == 0 && bloc_pair < 13)
		bloc_pair = bloc_pair + 2;
	if (bloc_pair == 12)
		return (-1);
	dist_begin_pair = 0;
	dist_end_pair = 0;
	begin_a = *stack_a;
	end_a = *stack_a;
	while (end_a->next)
	{
		dist_end_pair++;
		end_a = end_a->next;
	}
	while (end_a->bloc != bloc_pair && begin_a->bloc != bloc_pair)
	{
		dist_begin_pair++;
		begin_a = begin_a->next;
		dist_end_pair--;
		end_a = end_a->previous;
	}
	if (begin_a->bloc == bloc_pair)
		return (dist_begin_pair);
	else
		return (dist_end_pair);	
}