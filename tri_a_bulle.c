/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_a_bulle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:27:36 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/22 15:53:56 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE_TAB 10

int	main(void)
{
	int	tab[10] = {4, -1, 8, 12, 33, -6, 23, 2, 28, 24};
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < SIZE_TAB - 1)
	{
		j = 0;
		while (j < SIZE_TAB - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	j = 0;
	while (j <= SIZE_TAB - 1)
	{
		printf("%d\n", tab[j]);
		j++;
	}
	return (0);
}
