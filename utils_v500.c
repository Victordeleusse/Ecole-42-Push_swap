/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:41:13 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 11:19:53 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_init_bloc_500(t_stack_list **stack_a, int size_init)
{
	t_stack_list	*begin_a;
	int				mediane_index;
	int				starting_bloc_pair;
	int				starting_bloc_impair;

	begin_a = *stack_a;
	while (begin_a)
	{
		mediane_index = size_init / 2;
		if (begin_a->index_sorted > mediane_index)
		{	
			starting_bloc_impair = 1;
			while (mediane_index < (size_init + 1))
			{
				if (begin_a->index_sorted > mediane_index && begin_a->index_sorted <= mediane_index + 25)
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
		else
		{
			starting_bloc_pair = 2;
			while (mediane_index >= 0)
			{
				if (begin_a->index_sorted <= mediane_index && begin_a->index_sorted > mediane_index - 25)
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

int	ft_distance_min_impair_500(t_stack_list **stack_a)
{
	int				bloc_impair;
	int				dist_begin_impair;
	int				dist_end_impair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;

	bloc_impair = 1;
	while (ft_is_bloc_present_500(stack_a, bloc_impair) == 0 && bloc_impair < 20)
		bloc_impair = bloc_impair + 2;
	if (bloc_impair == 21)
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
	if (dist_min_pair <= dist_min_impair && dist_min_impair < size_stack / 2)
	{
		*bool = 2;
		dist_min = dist_min_pair;
	}
	else if (dist_min_pair <= dist_min_impair && dist_min_pair < (size_stack - dist_min_impair))
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

void ft_send_a_to_b_500(t_stack_list **stack_a, t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	bool;
	int distance;
	int	size_stack;
	int	mid_stack;
	int	nb_operation;

	bool = 0;
	distance = ft_distance_500(stack_a, &bool);
	size_stack = ft_get_stack_size(stack_a);
	mid_stack = size_stack / 2;
	if (distance > mid_stack)
	{
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

int	ft_get_max_in_bloc_25(t_stack_list **stack, int working_bloc)
{
	t_stack_list	*begin;
	int				index_max;

	begin = *stack;
	index_max = 0;
	while (begin)
	{
		if (begin->index_sorted > index_max && begin->bloc == working_bloc)
			index_max = begin->index_sorted;
		begin = begin->next;
	}
	return(index_max);
}

void	ft_send_max_in_bloc_25_from_b_to_a(t_stack_list **stack_a, t_stack_list **stack_b, int index_max, t_instruction_list **instruction_list)
{
	t_stack_list	*begin_b;
	int				size_stack;
	int				distance;

	size_stack = ft_get_stack_size(stack_b);
	distance = 0;
	begin_b = *stack_b;
	while (begin_b && begin_b->index_sorted != index_max)
	{
		distance++;
		begin_b = begin_b->next;
	}
	if (distance <= 12 || (distance > 12 && distance < 25 && size_stack > 25))
	{
		while (distance)
		{
			ft_rotate_b(stack_b, instruction_list);
			distance--;
		}
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
	}
	else if ((distance > 12 && distance < 25 && size_stack <= 25) || distance >= 25)
	{
		distance = size_stack - distance;
		while (distance)
		{
			ft_reverse_rotate_b(stack_b, instruction_list);
			distance--;
		}
		ft_push_b_to_a(stack_b, stack_a, instruction_list);
	}
}

void	ft_send_max_from_b_to_a_500(t_stack_list **stack_a, t_stack_list **stack_b, int working_bloc, t_instruction_list **instruction_list)
{
	int index_max;

	index_max = ft_get_max_in_bloc_25(stack_b, working_bloc);
	ft_send_max_in_bloc_25_from_b_to_a(stack_a, stack_b, index_max, instruction_list);
}

void	ft_send_b_to_a_500(t_stack_list **stack_a, t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int	working_bloc;

	working_bloc = (*stack_b)->bloc;
	while(working_bloc > 0)
	{
		while (ft_is_bloc_present(stack_b, working_bloc) == 1)
			ft_send_max_from_b_to_a_500(stack_a, stack_b, working_bloc, instruction_list);
		working_bloc = working_bloc - 2;
	}
	if (working_bloc <= 0 && !(*stack_b))
		return ;
	working_bloc = (*stack_b)->bloc;
	while(working_bloc <= 20)
	{
		while (ft_is_bloc_present(stack_b, working_bloc) == 1)
			ft_send_max_from_b_to_a_500(stack_a, stack_b, working_bloc, instruction_list);
		working_bloc = working_bloc + 2;
	}
}
