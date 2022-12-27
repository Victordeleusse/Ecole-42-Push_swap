/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/27 16:10:59 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	t_stack_list	**stack_a;
	t_stack_list	**stack_b;
	t_stack_list	*begin_a;
	int				count;
	int 			mediane;
	int				is_circulaire;

	count = 0;
	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	ft_get_index_sorted(stack_a, tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	// ft_sort_3(stack_a, &count);
	mediane = ft_get_mediane_index(argc);
	printf("Mediane index : %d\n", mediane);
	is_circulaire = ft_is_circular(stack_a);
	printf("Circulaire ? %d\n", is_circulaire);
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		printf("indice : %d\n", begin_a->index_sorted);
		begin_a = begin_a->next;
	}
	printf("\n");
	printf("\nCOMPTEUR : %d\n", count);
	return (0);
}
