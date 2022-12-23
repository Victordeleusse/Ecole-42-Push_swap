/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/23 16:47:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int				*tab;
	int				*sorted_tab;
	t_stack_list	**stack_a;
	t_stack_list	**stack_b;
	t_stack_list	*begin_a;
	int				i = 0;
	int				mediane;

	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	begin_a = *stack_a;
	while (begin_a)
	{
		printf("data : %d\n", begin_a->data);
		begin_a = begin_a->next;
	}
	sorted_tab = ft_sort(tab, argc);
	while (i < argc - 1)
	{
		printf("%d\n", sorted_tab[i]);
		i++;
	}
	mediane = ft_get_mediane(sorted_tab, argc);
	printf("mediane de la liste : %d", mediane);
	return (0);
}
