/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/04 18:46:39 by vde-leus         ###   ########.fr       */
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
	int				size_a;
	int				size_b;

	count = 0;
	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	ft_get_index_sorted(stack_a, tab, argc);
	if (argc - 1 <= 5)
		ft_sort_5(stack_a, stack_b, &count);
	else if (argc - 1 <= 10)
	{
		ft_separate_stack(stack_a, stack_b, &count, argc - 1);
		ft_sort_5(stack_a, stack_b, &count);
		ft_restore_b_to_a(stack_b, stack_a, &count);
	}
	else if (argc - 1 <= 100)
	{
		ft_init_bloc(stack_a, argc - 1);
		size_a = ft_get_stack_size(stack_a);
		while ((*stack_a))
			ft_send_a_to_b(stack_a, stack_b, &count);
		size_b = ft_get_stack_size(stack_b);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
		printf("\nAFFICHAGE DE B\n");
		begin_b = *stack_b;
		while (begin_b)
		{
			printf("data : %d\n", begin_b->data);
			// printf("indice : %d\n", begin_a->index_sorted);
			printf("bloc : %d\n\n", begin_b->bloc);
			begin_b = begin_b->next;
		}
		printf("\nAFFICHAGE DE A\n");
		begin_a = *stack_a;
		while (begin_a)
		{
			printf("data : %d\n", begin_a->data);
			// printf("indice : %d\n", begin_a->index_sorted);
			printf("bloc : %d\n\n", begin_a->bloc);
			begin_a = begin_a->next;
		}
		printf("\nsize A init : %d vs. size B fin : %d\n", size_a, size_b);
	}
	
	printf("\nCOMPTEUR : %d\n\n\n", count);
	return (0);
}
