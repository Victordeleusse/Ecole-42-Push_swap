/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/08 13:42:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	t_stack_list	**stack_a;
	t_stack_list	**stack_b;
	t_stack_list	*begin_a;
	// t_stack_list	*begin_b;
	int				count;
	// int				size_a;
	// int				size_b;

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
		while ((*stack_a))
			ft_send_a_to_b(stack_a, stack_b, &count);
		// printf("\nAFFIChAGE DE B");
		// begin_b = *stack_b;
		// while (begin_b)
		// {
		// 	printf("indice -> %d | bloc : %d\n", begin_b->index_sorted, begin_b->bloc);
		// 	begin_b = begin_b->next;
		// }
		while (*stack_b)
			ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count);
	}
	else if (argc - 1 <= 500)
	{
		ft_init_bloc_500(stack_a, argc - 1);
		begin_a = *stack_a;
		while (begin_a)
		{
			printf("indice -> %d | bloc : %d\n", begin_a->index_sorted, begin_a->bloc);
			begin_a = begin_a->next;
		}
		while ((*stack_a))
			ft_send_a_to_b_500(stack_a, stack_b, &count);
	}
	printf("\nCOMPTEUR : %d\n\n\n", count);
	return (0);
}
