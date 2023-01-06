/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:07:28 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/06 14:09:08 by vde-leus         ###   ########.fr       */
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
	dist_min_impair = ft_distance_min_impair(stack_a);
	dist_min_pair = ft_distance_min_pair(stack_a);
	if (dist_min_pair == -1)
		dist_min_pair = 200;
	if (dist_min_impair == -1)
		dist_min_impair = - 200;
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
		ft_push_a_to_b(stack_a, stack_b, count);
		if (bool == 2)
			ft_rotate_b(stack_b, count);
	}
	else
	{
		while (distance)
		{
			ft_rotate_a(stack_a, count);
			distance--;
		}
		ft_push_a_to_b(stack_a, stack_b, count);
		if (bool == 2)
			ft_rotate_b(stack_b, count);
	}
}

int	ft_get_max_in_bloc_10(t_stack_list **stack, int working_bloc)
{
	t_stack_list	*begin;
	int				index_max;

	begin = *stack;
	index_max = begin->index_sorted;
	while (begin && begin->bloc == working_bloc)
	{
		if (begin->index_sorted > index_max)
			index_max = begin->index_sorted;
		begin = begin->next;
	}
	return(index_max);
}

void	ft_cut_bloc_10_to_5_in_b(t_stack_list **stack_b, t_stack_list **stack_a, int *count)
{
	t_stack_list	*begin_b;
	int				working_bloc;
	int				max_bloc;
	int				nb_rotate;
	int				nb_already_pushed;
	
	nb_already_pushed = 0;
	working_bloc = (*stack_b)->bloc;
	max_bloc = ft_get_max_in_bloc_10(stack_b, working_bloc);
	begin_b = *stack_b;
	nb_rotate = 0;
	while (begin_b && begin_b->bloc == working_bloc && nb_already_pushed < 5)
	{
		if (begin_b->index_sorted > (max_bloc - 5))
		{
			ft_push_b_to_a(stack_b, stack_a, count);
			nb_already_pushed++;
		}
		else
		{
			ft_rotate_b(stack_b, count);
			nb_rotate++;
		}	
		begin_b = *stack_b;
	}
	while (nb_rotate != 0)
	{
		ft_reverse_rotate_b(stack_b, count);	
		nb_rotate--;
	}
	ft_sort_5_in_full_a(stack_a, stack_b, count);
	if ((*stack_b))
		ft_sort_5_in_full_b(stack_a, stack_b, count);
}

void	ft_sort_3_in_a_100(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	int	index_a;
	int	index_b;
	int	index_c;
	
	index_a = (*stack_a)->index_sorted;
	index_b = (*stack_a)->next->index_sorted;
	index_c = (*stack_a)->next->next->index_sorted;
	if (index_a < index_b && index_b < index_c && index_a < index_c)
		return ;
	else if (index_a < index_b && index_b > index_c && index_a < index_c)
	{
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_a(stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a < index_b && index_b > index_c && index_a > index_c)
	{
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_a(stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_a(stack_a, count);
	}
	else if (index_a > index_b && index_b < index_c && index_a < index_c)
		ft_swap_a(stack_a, count);
	else if (index_a > index_b && index_b < index_c && index_a > index_c)
	{
		ft_swap_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_a(stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a > index_b && index_b > index_c && index_a > index_c)
	{
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_a(stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_a(stack_a, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_a(stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
}

void	ft_sort_3_in_full_a(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	t_stack_list	*begin_a;
	int				working_bloc;
	int				taille;
	
	working_bloc = (*stack_a)->bloc;
	begin_a = *stack_a;
	taille = 0;
	while (begin_a && begin_a->bloc == working_bloc)
	{
		taille++;
		begin_a = begin_a->next;
	}
	if (taille == 0 || taille == 1)
		return ;
	else if (taille == 2)
	{
		begin_a = *stack_a;
		if (begin_a->index_sorted > begin_a->next->index_sorted)
			ft_swap_a(stack_a, count);
	}
	else if (taille == 3)
		ft_sort_3_in_a_100(stack_a, stack_b, count);
}

void	ft_sort_5_in_full_a(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	t_stack_list	*begin_a;
	t_stack_list	*begin_b;
	int				working_bloc;
	int				max_bloc;
	int				nb_rotate;
	int				i;
	
	i = 0;
	working_bloc = (*stack_a)->bloc;
	max_bloc = ft_get_max_in_bloc_10(stack_a, working_bloc);
	nb_rotate = 0;
	begin_a = *stack_a;
	if (ft_get_stack_size(stack_a) > 3)
	{
		while (begin_a->bloc == working_bloc && i < 5)
		{
			if (begin_a->index_sorted < (max_bloc - 2))
				ft_push_a_to_b(stack_a, stack_b, count);
			else
			{
				ft_rotate_a(stack_a, count);
				nb_rotate++;
			}	
			begin_a = *stack_a;
			i++;
		}
		while (nb_rotate != 0)
		{
			ft_reverse_rotate_a(stack_a, count);	
			nb_rotate--;
		}
	}
	begin_b = *stack_b;
	if (begin_b && begin_b->next && begin_b->index_sorted < begin_b->next->index_sorted)
		ft_swap_b(stack_b, count);
	ft_sort_3_in_full_a(stack_a, stack_b, count);
	if ((*stack_b) && (*stack_b)->bloc == working_bloc)
		ft_push_b_to_a(stack_b, stack_a, count);
	if ((*stack_b) && (*stack_b)->bloc == working_bloc)
		ft_push_b_to_a(stack_b, stack_a, count);
}

void	ft_send_3_from_b_in_a_100(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int working_bloc)
{
	int	index_a;
	int	index_b;
	int	index_c;
	
	if (!*stack_b || (*stack_b)->bloc != working_bloc) 
		return ;
	index_a = (*stack_b)->index_sorted;
	if (!(*stack_b)->next || (*stack_b)->next->bloc != working_bloc)
	{	
		ft_push_b_to_a(stack_b, stack_a, count);
		return ;
	}
	index_b = (*stack_b)->next->index_sorted;
	if (!(*stack_b)->next->next || (*stack_b)->next->next->bloc != working_bloc)
	{
		if (index_a > index_b)
		{
			ft_push_b_to_a(stack_b, stack_a, count);
			ft_push_b_to_a(stack_b, stack_a, count);
		}
		else
		{
			ft_swap_b(stack_b, count);
			ft_push_b_to_a(stack_b, stack_a, count);
			ft_push_b_to_a(stack_b, stack_a, count);
		}
		return ;
	}
	index_c = (*stack_b)->next->next->index_sorted;
	if (index_a > index_b && index_b > index_c && index_a > index_c)
	{	
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}	
	else if (index_a > index_b && index_b < index_c && index_a > index_c)
	{
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a < index_b && index_b < index_c && index_a < index_c)
	{
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a < index_b && index_b > index_c && index_a < index_c)
	{
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a < index_b && index_b > index_c && index_a > index_c)
	{
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
	else if (index_a > index_b && index_b < index_c && index_a < index_c)
	{
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_a_to_b(stack_a, stack_b, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_swap_b(stack_b, count);
		ft_push_b_to_a(stack_b, stack_a, count);
		ft_push_b_to_a(stack_b, stack_a, count);
	}
}

void	ft_sort_5_in_full_b(t_stack_list **stack_a, t_stack_list **stack_b, int *count)
{
	t_stack_list	*begin_a;
	t_stack_list	*begin_b;
	int				working_bloc;
	int				max_bloc;
	int				nb_rotate;
	int				i;
	
	i = 0;
	working_bloc = (*stack_b)->bloc;
	max_bloc = ft_get_max_in_bloc_10(stack_b, working_bloc);
	nb_rotate = 0;
	begin_b = *stack_b;
	if (ft_get_stack_size(stack_b) > 3)
	{
		while (begin_b->bloc == working_bloc && i < 5)
		{
			
			if (begin_b->index_sorted > (max_bloc - 2))
				ft_push_b_to_a(stack_b, stack_a, count);
			else
			{
				ft_rotate_b(stack_b, count);
				nb_rotate++;
			}	
			begin_b = *stack_b;
			i++;
		}
		while (nb_rotate != 0)
		{
			ft_reverse_rotate_b(stack_b, count);	
			nb_rotate--;
		}
	}
	begin_a = *stack_a;
	if (begin_a->index_sorted > begin_a->next->index_sorted)
		ft_swap_a(stack_a, count);
	ft_send_3_from_b_in_a_100(stack_a, stack_b, count, working_bloc);
}
