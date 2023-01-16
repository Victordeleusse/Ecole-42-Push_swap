/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:09:41 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/16 15:04:33 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_operation_bonus_swap_push_rev(t_instruction_list *begin, \
	t_instruction_list *instruction_lst_annexe, \
	t_stack_list **stack_a, t_stack_list **stack_b)
{
	if (begin->instruction[0] == 's' && begin->instruction[1] == 'a')
		ft_swap_a(stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 's' && begin->instruction[1] == 'b')
		ft_swap_b(stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'p' && begin->instruction[1] == 'a')
		ft_push_b_to_a(stack_b, stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'p' && begin->instruction[1] == 'b')
		ft_push_a_to_b(stack_a, stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'a')
		ft_reverse_rotate_a(stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'b')
		ft_rotate_b(stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'b')
		ft_reverse_rotate_b(stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'r')
	{
		ft_reverse_rotate_a(stack_a, &instruction_lst_annexe);
		ft_reverse_rotate_b(stack_b, &instruction_lst_annexe);
	}
}

void	ft_operation_bonus_rotate(t_instruction_list **instruction_lst, \
	t_stack_list **stack_a, t_stack_list **stack_b)
{
	t_instruction_list	*instruction_lst_annexe;
	t_instruction_list	*begin;

	begin = *instruction_lst;
	instruction_lst_annexe = ft_generate_instruction_element("1");
	if (!instruction_lst_annexe)
		return ;
	while (begin)
	{
		if (begin->instruction[0] == 'r' && begin->instruction[1] == 'a')
			ft_rotate_a(stack_a, &instruction_lst_annexe);
		else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
			&& begin->instruction[2] == '\0')
		{
			ft_rotate_a(stack_a, &instruction_lst_annexe);
			ft_rotate_b(stack_b, &instruction_lst_annexe);
		}
		else
			ft_operation_bonus_swap_push_rev(begin, instruction_lst_annexe, \
				stack_a, stack_b);
		begin = begin->next;
	}
	ft_free_instruction_list(instruction_lst_annexe->next);
	free(instruction_lst_annexe);
}

int	ft_check_checker(t_stack_list **stack_a, int argc)
{
	int					count;
	t_stack_list		*begin_a;

	begin_a = *stack_a;
	count = 0;
	if (begin_a->index_sorted != 1)
		return (0);
	while (begin_a->next)
	{
		if (begin_a->index_sorted != begin_a->next->index_sorted - 1)
			return (0);
		begin_a = begin_a->next;
		count++;
	}
	if (begin_a->index_sorted != argc - 1 || count != argc - 2)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int					*tab;
	t_instruction_list	*instruction_lst;
	t_stack_list		**stack_a;
	t_stack_list		**stack_b;

	if (argc == 1)
		return (0);
	instruction_lst = ft_generate_instruction_list(0);
	tab = ft_generate_tab_int(argc, argv);
	if (!instruction_lst || !tab)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	if (!stack_a || !stack_b)
		return (0);
	ft_get_index_sorted(stack_a, tab, argc);
	ft_operation_bonus_rotate(&instruction_lst, stack_a, stack_b);
	if (ft_check_checker(stack_a, argc) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_free_bonus(stack_a, stack_b, instruction_lst, tab);
	return (0);
}
