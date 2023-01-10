/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_bulle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:27:36 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 11:08:34 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/* Tri du tableau initial et mise en place des indices 
// de chaque elemenent du stack */

int	*ft_tab_copy(int *tab, int argc)
{
	int	*sorted_tab;
	int	i;

	sorted_tab = ft_calloc(sizeof(int), argc -1);
	i = 0;
	while (i <= argc - 2)
	{
		sorted_tab[i] = tab[i];
		i++;
	}
	return (sorted_tab);
}

int	*ft_sort(int *tab, int argc)
{
	int	*sorted_tab;
	int	temp;
	int	i;
	int	j;

	sorted_tab = ft_tab_copy(tab, argc);
	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		while (j < argc - i - 2)
		{
			if (sorted_tab[j] > sorted_tab[j + 1])
			{
				temp = sorted_tab[j + 1];
				sorted_tab[j + 1] = sorted_tab[j];
				sorted_tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sorted_tab);
}

void	ft_get_index_sorted(t_stack_list **stack_a, int *tab, int argc)
{
	t_stack_list	*begin;
	int				*sorted_tab;
	int				i;

	sorted_tab = ft_sort(tab, argc);
	i = 0;
	while (i < argc - 1)
	{
		begin = *stack_a;
		while (begin)
		{
			if (sorted_tab[i] == begin->data)
			{
				begin->index_sorted = (i + 1);
				break ;
			}
			begin = begin->next;
		}
		i++;
	}
	free (sorted_tab);
}

int	ft_get_mediane_value(int *tab, int size_tab)
{
	if (size_tab % 2 == 0)
		return (tab[(size_tab - 1) / 2]);
	else
		return (tab[size_tab / 2]);
}

void	ft_double_reverse_rotate(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	ft_reverse_rotate_a(stack_a, instruction_list);
	ft_reverse_rotate_b(stack_b, instruction_list);
}
