/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:11:51 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:13:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* ATTENTION : Decalage de 1 entre size_stack et dist_min_impair -> dist_min 
// pour bool == 1 est > 0 (!= dist_min pour bool == 2 qui est >= 0) */

int	ft_calc_dist_min(int dist_min_pair, int dist_min_impair, \
	int size_stack, int *bool)
{
	int	dist_min;

	if (dist_min_pair <= dist_min_impair && dist_min_impair < size_stack / 2)
	{
		*bool = 2;
		dist_min = dist_min_pair;
	}
	else if (dist_min_pair <= dist_min_impair && \
		dist_min_pair < (size_stack - dist_min_impair))
	{
		*bool = 2;
		dist_min = dist_min_pair;
	}
	else
	{
		*bool = 1;
		dist_min = dist_min_impair;
	}
	return (dist_min);
}

int	ft_distance_100(t_stack_list **stack_a, int *bool)
{
	int	dist_min;
	int	dist_min_pair;
	int	dist_min_impair;
	int	size_stack;

	size_stack = ft_get_stack_size(stack_a);
	dist_min_impair = ft_distance_min_impair(stack_a);
	dist_min_pair = ft_distance_min_pair(stack_a);
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

void	ft_send_a_to_b_from_top(t_stack_list **stack_a, t_stack_list **stack_b, \
		t_instruction_list **instruction_list)
{
	int	bool;
	int	distance;
	int	size_stack;
	int	nb_operation;

	bool = 0;
	distance = ft_distance_100(stack_a, &bool);
	size_stack = ft_get_stack_size(stack_a);
	nb_operation = size_stack - distance;
	while (nb_operation)
	{
		ft_reverse_rotate_a(stack_a, instruction_list);
		nb_operation--;
	}
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	if (bool == 2)
		ft_rotate_b(stack_b, instruction_list);
}

void	ft_send_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, \
		t_instruction_list **instruction_list)
{
	int	bool;
	int	distance;
	int	size_stack;
	int	mid_stack;

	bool = 0;
	distance = ft_distance_100(stack_a, &bool);
	size_stack = ft_get_stack_size(stack_a);
	mid_stack = size_stack / 2;
	if (distance > mid_stack)
	{
		ft_send_a_to_b_from_top(stack_a, stack_b, instruction_list);
	}
	else
	{
		while (distance)
		{
			ft_rotate_a(stack_a, instruction_list);
			distance--;
		}
		ft_push_a_to_b(stack_a, stack_b, instruction_list);
		if (bool == 2)
			ft_rotate_b(stack_b, instruction_list);
	}
}
