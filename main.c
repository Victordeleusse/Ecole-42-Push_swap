/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/03 14:38:21 by vde-leus         ###   ########.fr       */
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
		ft_separate_stack(stack_a, stack_b, &count, argc - 1);
	ft_sort_5(stack_a, stack_b, &count);
	ft_restore_b_to_a(stack_b, stack_a, &count);
	printf("\nAFFICHAGE DE A TRIE \n");
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		printf("indice : %d\n", begin_a->index_sorted);
		// printf("bloc : %d\n\n", begin_a->bloc);
		begin_a = begin_a->next;
	}
	printf("\nCOMPTEUR : %d\n\n\n", count);
	return (0);
}
