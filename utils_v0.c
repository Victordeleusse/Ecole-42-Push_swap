/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_v0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:01:06 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/02 18:12:46 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* Determine la mediane de mon stack : son indice aka sa position
// ainsi que sa valeur */

int	ft_get_stack_size(t_stack_list **stack)
{
	int				size_stack;
	t_stack_list	*begin;

	if (!*stack)
		return (0);
	begin = *stack;
	size_stack = 0;
	while (begin)
	{
		begin = begin->next;
		size_stack++;
	}
	return (size_stack);
}

int	ft_get_index_max(t_stack_list **stack)
{
	int				index_max;
	t_stack_list	*begin;

	begin = *stack;
	index_max = begin->index_sorted;
	while (begin->next)
	{	
		if (index_max < begin->index_sorted)
			index_max = begin->index_sorted;
		begin = begin->next;
	}
	return (index_max);
}

int	ft_get_index_min(t_stack_list **stack)
{
	int				index_min;
	t_stack_list	*begin;

	begin = *stack;
	index_min = begin->index_sorted;
	while (begin->next)
	{	
		if (index_min > begin->index_sorted)
			index_min = begin->index_sorted;
		begin = begin->next;
	}
	return (index_min);
}

/* !! Calcul de la mediane sup !! */

int	ft_get_mediane_index(t_stack_list **stack)
{
	int	index_max;
	int	index_min;
	int	delta;

	index_max = ft_get_index_max(stack);
	index_min = ft_get_index_min(stack);
	delta = index_max - index_min + 3;
	if (delta % 2 == 0)
		return ((delta - 1) / 2 + 1);
	else
		return (delta / 2);
}

int	ft_get_mediane_position(t_stack_list **stack)
{
	int				mediane;
	int				position;
	t_stack_list	*begin;

	position = 1;
	mediane = ft_get_mediane_index(stack);
	begin = *stack;
	while (begin->index_sorted != mediane && position <= 5)
	{
		begin = begin->next;
		position++;
	}
	return (position);
}