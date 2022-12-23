/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/23 12:04:08 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	t_stack_list	**stack_a;
	t_stack_list	**stack_b;
	t_stack_list	*begin_a;
	// t_stack_list	*pop;
	// t_stack_list	*pop_last;
	// t_stack_list	*pop2;
	// t_stack_list	*pop3;
	// t_stack_list	*pop4;
	// t_stack_list	*pop5;
	int				count;
	int				resultat;
	
	resultat = ft_atoi("55", &count);
	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
	{
		ft_printf("Mauvaise valeur d entree");
		return (0);
	}
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		begin_a = begin_a->next;
	}
	// ft_swap_fs(stack_a);
	// pop = ft_pop(stack_a);
	// pop2 = ft_pop(stack_a);
	// pop3 = ft_pop(stack_a);
	// pop4 = ft_pop(stack_a);
	// pop5 = ft_pop(stack_a);
	// printf("data pop : %d\n", pop->data);
	// printf("data pop2 : %d\n", pop2->data);
	// printf("data pop3 : %d\n", pop3->data);
	// printf("data pop4 : %d\n", pop4->data);
	// if (pop5 != NULL)
	// 	printf("data pop5 : %d\n", pop5->data);
	// ft_add(stack_a, pop);
	// ft_rotate(stack_a);
	// ft_reverse_rotate(stack_a);
	// //pop_last = ft_pop_last(stack_a);
	// //printf("data pop last : %d\n", pop_last->data);
	// begin_a = *stack_a;
	// while (begin_a)
	// {
	// 	printf("data : %d\n", begin_a->data);
	// 	begin_a = begin_a->next;
	// }
	return (0);
}
