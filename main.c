/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/09 17:53:05 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int					*tab;
	t_stack_list		**stack_a;
	t_stack_list		**stack_b;
	t_instruction_list	*instruction_list;
	t_instruction_list	*begin_list;
	t_instruction_list	*begin_list_2;
	t_instruction_list	*begin_list_3;
	t_instruction_list	*begin_list_4;
	t_instruction_list	*begin_list_final;
	int					count;

	count = 0;
	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	ft_get_index_sorted(stack_a, tab, argc);
	instruction_list = ft_generate_instruction_element("start");
	begin_list = instruction_list;
	begin_list_2 = instruction_list;
	begin_list_3 = instruction_list;
	// begin_list_4 = instruction_list;
	begin_list_final = instruction_list;
	if (argc - 1 <= 5)
		ft_sort_5(stack_a, stack_b, &count, &instruction_list);
	else if (argc - 1 <= 10)
	{
		ft_separate_stack(stack_a, stack_b, &count, argc - 1, &instruction_list);
		ft_sort_5(stack_a, stack_b, &count, &instruction_list);
		ft_restore_b_to_a(stack_b, stack_a, &count, &instruction_list);
	}
	else if (argc - 1 <= 100)
	{
		ft_init_bloc(stack_a, argc - 1);
		while ((*stack_a))
			ft_send_a_to_b(stack_a, stack_b, &count, &instruction_list);
		while (*stack_b)
			ft_cut_bloc_10_to_5_in_b(stack_b, stack_a, &count, &instruction_list);
	}
	else if (argc - 1 <= 500)
	{
		ft_init_bloc_500(stack_a, argc - 1);
		while ((*stack_a))
			ft_send_a_to_b_500(stack_a, stack_b, &count, &instruction_list);
		ft_send_b_to_a_500(stack_a, stack_b, &count, &instruction_list);
	}
	begin_list = begin_list->next;
	ft_opti_swap(&instruction_list, &count);
	begin_list_2 = begin_list_2->next;
	ft_opti_rotate(&instruction_list, &count);
	begin_list_3 = begin_list_3->next;
	ft_opti_reverse_rotate(&instruction_list, &count);
	begin_list_4 = instruction_list;
	begin_list_4 = begin_list_4->next;
	while (begin_list_4)
	{
		ft_printf("%s\n", begin_list_4->instruction);
		begin_list_4 = begin_list_4->next;
	}
	printf("instruction list first: %s\n", instruction_list->instruction);
	ft_free_instruction_list(instruction_list);
	// ft_free_stack(stack_a);
	// ft_free_stack(stack_b);
	// free(tab);
	return(0);
}
