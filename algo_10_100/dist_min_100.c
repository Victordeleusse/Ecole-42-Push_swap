/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_min_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:08:10 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:08:37 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_init_dist_impair_100(t_stack_list **stack_a, int *dist_begin_impair, \
	int *dist_end_impair, int *bloc_impair)
{
	*bloc_impair = 1;
	*dist_begin_impair = 0;
	*dist_end_impair = 0;
	while (ft_is_bloc_present(stack_a, *bloc_impair) == 0 && *bloc_impair < 10)
		*bloc_impair = *bloc_impair + 2;
}

t_stack_list	*ft_last_elem_stack(t_stack_list **stack_a, \
	int *dist_end_impair)
{
	t_stack_list	*end_a;

	end_a = *stack_a;
	while (end_a->next)
	{
		*dist_end_impair = *dist_end_impair + 1;
		end_a = end_a->next;
	}
	return (end_a);
}

int	ft_distance_min_impair(t_stack_list **stack_a)
{
	int				bloc_impair;
	int				dist_begin_impair;
	int				dist_end_impair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;

	ft_init_dist_impair_100(stack_a, &dist_begin_impair, \
		&dist_end_impair, &bloc_impair);
	if (bloc_impair == 11)
		return (-1);
	begin_a = *stack_a;
	end_a = ft_last_elem_stack(stack_a, &dist_end_impair);
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

void	ft_init_dist_pair_100(t_stack_list **stack_a, int *dist_begin_pair, \
	int *dist_end_pair, int *bloc_pair)
{
	*bloc_pair = 2;
	*dist_begin_pair = 0;
	*dist_end_pair = 0;
	while (ft_is_bloc_present(stack_a, *bloc_pair) == 0 && *bloc_pair < 11)
		*bloc_pair = *bloc_pair + 2;
}

int	ft_distance_min_pair(t_stack_list **stack_a)
{
	int				bloc_pair;
	int				dist_begin_pair;
	int				dist_end_pair;
	t_stack_list	*begin_a;
	t_stack_list	*end_a;

	ft_init_dist_pair_100(stack_a, &dist_begin_pair, \
		&dist_end_pair, &bloc_pair);
	if (bloc_pair == 12)
		return (-1);
	begin_a = *stack_a;
	end_a = ft_last_elem_stack(stack_a, &dist_end_pair);
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
