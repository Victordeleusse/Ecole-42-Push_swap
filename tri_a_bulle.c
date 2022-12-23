/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_bulle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:27:36 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/23 16:45:46 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_get_mediane(int *tab, int argc)
{
	if ((argc - 1) % 2 == 0)
		return (tab[((argc - 1) - 1) / 2]);
	else
		return (tab[(argc - 1) / 2]);
}