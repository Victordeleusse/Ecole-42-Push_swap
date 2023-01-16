/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:36 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/16 13:40:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_instruction_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_bonus(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int *tab)
{
	ft_free_instruction_list(instruction_list->next);
	free(instruction_list->instruction);
	free(instruction_list);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(tab);
}
