/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/01 22:54:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	t_stack_list	**stack_a;
	t_stack_list	**stack_b;
	t_stack_list	*begin_a;
	t_stack_list	*begin_b;
	int				count;
	// int 			mediane_index;

	count = 0;
	tab = ft_generate_tab_int(argc, argv);
	printf("tab : %d\n", tab[2]);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	ft_get_index_sorted(stack_a, tab, argc);
	// mediane_index = ft_get_mediane_index(stack_a);
	// printf("mediane : %d\n", mediane_index);
	ft_prepare_stack(stack_a, stack_b, &count);
	ft_prepare_stack(stack_a, stack_b, &count);
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		printf("indice : %d\n", begin_a->index_sorted);
		begin_a = begin_a->next;
	}
	printf("\nAFFICHAGE DE B\n");
	begin_b = *stack_b;
	while (begin_b)
	{
		printf("data : %d\n", begin_b->data);
		printf("indice : %d\n", begin_b->index_sorted);
		begin_b = begin_b->next;
	}
	printf("\nCOMPTEUR : %d\n", count);
	return (0);
}
