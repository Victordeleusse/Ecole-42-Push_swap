/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:07:28 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/04 12:07:28 by vde-leus         ###   ########.fr       */
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
	while (ft_is_bloc_present(stack_a, bloc_pair) == 0 && bloc_pair < 11)
		bloc_pair = bloc_pair + 2;
	printf("Bloc pair : %d\n", bloc_pair);
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

/* ATTENTION : Decalage de 1 entre size_stack et dist_min_impair -> dist_min pour bool == 1 est > 0 
// (!= dist_min pour bool == 2 qui est >= 0) */

int	ft_distance_100(t_stack_list **stack_a, int *bool)
{
	int	dist_min;
	int	dist_min_pair;
	int	dist_min_impair;
	int	size_stack;
	
	size_stack = ft_get_stack_size(stack_a);
	printf("\nSize du stack : %d\n", size_stack);
	dist_min_impair = ft_distance_min_impair(stack_a);
	printf("\ndist min impair : %d\n", dist_min_impair);
	dist_min_pair = ft_distance_min_pair(stack_a);
	printf("\ndist min pair : %d\n", dist_min_pair);
	if (dist_min_pair == -1)
		dist_min_pair = 200;
	if (dist_min_impair == -1)
		dist_min_impair = 200;
	if (dist_min_pair <= (size_stack - dist_min_impair))
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

void ft_send_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	int	bool;
	int distance;
	int	size_stack;
	int	mid_stack;
	int	nb_operation;

	bool = 0;
	distance = ft_distance_100(stack_a, &bool);
	printf("DISTANCE %d\n", distance);
	size_stack = ft_get_stack_size(stack_a);
	mid_stack = size_stack / 2;
	if (distance > mid_stack)
	{
		nb_operation = size_stack - distance;
		while (nb_operation)
		{
			ft_reverse_rotate_a(stack_a, count);
			nb_operation--;
		}
		printf("DATA ENVOYEE : %d\n", (*stack_a)->data);
		ft_push_a_to_b(stack_a, stack_b, count);
		printf("haut ou bas : %d\n", bool);
	}
	else
	{
		while (distance)
		{
			ft_rotate_a(stack_a, count);
			distance--;
		}
		printf("DATA ENVOYEE : %d\n", (*stack_a)->data);
		ft_push_a_to_b(stack_a, stack_b, count);
		printf("haut ou bas : %d\n", bool);
	}
}