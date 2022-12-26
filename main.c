/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/26 16:24:19 by vde-leus         ###   ########.fr       */
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
	int				A_stack_size;
	int				stop_index;

	count = 0;
	A_stack_size = argc - 1;
	tab = ft_generate_tab_int(argc, argv);
	stop_index = ft_stop_index(tab, argc);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	begin_a = *stack_a;
	printf("\nOPERATIONS DE TRI\n\n");
	ft_sort_stack_1(stack_a, stack_b, &count, &A_stack_size);
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		begin_a = begin_a->next;
	}
	printf("\n\nnombre d operations : %d\n\n", count);
	return (0);
}
