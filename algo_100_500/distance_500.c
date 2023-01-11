/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:47:22 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 10:47:39 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_calculate_dist_min_impair(t_stack_list **begin_a, \
	t_stack_list **end_a, int *dist_begin_impair, int *dist_end_impair)
{
	*dist_begin_impair = *dist_begin_impair + 1;
	(*begin_a) = (*begin_a)->next;
	*dist_end_impair = *dist_end_impair - 1;
	(*end_a) = (*end_a)->previous;
}

int	ft_distance_min_impair_500(t_stack_list **stack_a)
{
	int				bloc_impair;
	int				dist_begin_impair;
	int				dist_end_impair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;

	bloc_impair = 1;
	while (ft_is_bloc_present_500(stack_a, bloc_impair) == 0 && \
			bloc_impair < 20)
		bloc_impair = bloc_impair + 2;
	if (bloc_impair == 21)
		return (-1);
	dist_begin_impair = 0;
	dist_end_impair = 0;
	end_a = ft_last_elem_stack(stack_a, &dist_end_impair);
	begin_a = *stack_a;
	while (end_a->bloc != bloc_impair && begin_a->bloc != bloc_impair)
		ft_calculate_dist_min_impair(&begin_a, &end_a, \
			&dist_begin_impair, &dist_end_impair);
	if (begin_a->bloc == bloc_impair)
		return (dist_begin_impair);
	else
		return (dist_end_impair);
}

int	ft_distance_min_pair_500(t_stack_list **stack_a)
{
	int				bloc_pair;
	int				dist_begin_pair;
	int				dist_end_pair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;

	bloc_pair = 2;
	while (ft_is_bloc_present_500(stack_a, bloc_pair) == 0 && bloc_pair < 21)
		bloc_pair = bloc_pair + 2;
	if (bloc_pair == 22)
		return (-1);
	dist_begin_pair = 0;
	dist_end_pair = 0;
	begin_a = *stack_a;
	end_a = ft_last_elem_stack(stack_a, &dist_end_pair);
	while (end_a->bloc != bloc_pair && begin_a->bloc != bloc_pair)
		ft_calculate_dist_min_impair(&begin_a, &end_a, \
			&dist_begin_pair, &dist_end_pair);
	if (begin_a->bloc == bloc_pair)
		return (dist_begin_pair);
	else
		return (dist_end_pair);
}

int	ft_distance_500(t_stack_list **stack_a, int *bool)
{
	int	dist_min;
	int	dist_min_pair;
	int	dist_min_impair;
	int	size_stack;

	size_stack = ft_get_stack_size(stack_a);
	dist_min_impair = ft_distance_min_impair_500(stack_a);
	dist_min_pair = ft_distance_min_pair_500(stack_a);
	if (dist_min_pair == -1)
	{	
		*bool = 1;
		return (dist_min_impair);
	}
	if (dist_min_impair == -1)
	{	
		*bool = 2;
		return (dist_min_pair);
	}
	dist_min = ft_calc_dist_min(dist_min_pair, \
		dist_min_impair, size_stack, bool);
	return (dist_min);
}
