/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:39:47 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/23 15:22:03 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_int(int number, char *str, int count)
{
	if ((str[0] == '-' && number > 0) || (str[0] != '-' && number < 0))
	{
		ft_printf("ERROR : %s is not an int !\n", str);
		return (0);
	}
	if (count == 0)
	{
		ft_printf("ERROR : %s is not a number !\n", str);
		return (0);
	}
	return (1);
}

int	ft_is_already_present(int number, int *tab, int taille)
{
	int	j;

	j = 0;
	while (j < taille)
	{
		if (tab[j] == number)
		{
			ft_printf("ERROR : number %d is already present \
in the list \n", number);
			return (0);
		}
		j++;
	}
	return (1);
}
