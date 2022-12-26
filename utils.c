/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:01:06 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/26 16:30:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_get_pos_min(t_stack_list **stack_a)
{
	t_stack_list	*min_stack;
	t_stack_list	*begin_stack;
	int				pos_min;
	int				k;

	pos_min = 0;
	k = 0;
	if (!*stack_a)
		return (0);
	min_stack = *stack_a;
	begin_stack = *stack_a;
	if (!min_stack->next)
		return (0);
	while (begin_stack)
	{
		if (min_stack->data > begin_stack->data)
		{
			min_stack = begin_stack;
			pos_min = k;
		}
		begin_stack = begin_stack->next;
		k++;
	}
	return (pos_min);
}

void	ft_get_min_first(t_stack_list **stack_a, int *size_stack, int *count)
{
	int	middle;
	int	pos_min;

	if (*size_stack % 2 == 0)
		middle = *size_stack / 2;
	else
		middle = (*size_stack + 1) / 2;
	pos_min = ft_get_pos_min(stack_a);
	if (pos_min <= middle)
	{
		while (pos_min != 0)
		{	
			ft_rotate(stack_a, count);
			pos_min--;
		}
	}
	else
	{
		pos_min = *size_stack - pos_min;
		while (pos_min != 0)
		{
			ft_reverse_rotate(stack_a, count);
			pos_min--;
		}
	}
}

void	ft_sort_stack_1(t_stack_list **stack_1, t_stack_list **stack_2, \
	int *count, int *size_stack_1)
{
	int	size_stack_2_theo;

	size_stack_2_theo = *size_stack_1 - 1;
	while (*size_stack_1 != 1)
	{
		ft_get_min_first(stack_1, size_stack_1, count);
		ft_push(stack_1, stack_2, count, size_stack_1);
	}
	while (size_stack_2_theo != 0)
		ft_push(stack_2, stack_1, count, &size_stack_2_theo);
}
