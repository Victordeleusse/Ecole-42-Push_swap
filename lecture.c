/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:32:33 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/30 21:41:01 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*ft_generate_tab_int(int argc, char **argv)
{
	int	i;
	int	number;
	int	*tab;
	int	count;

	i = 0;
	tab = ft_calloc(sizeof(int), argc -1);
	while (i < argc - 1)
	{
		count = 0;
		number = ft_atoi(argv[i + 1], &count);
		if (ft_is_int(number, argv[i + 1], count) == 0)
			return (NULL);
		if (ft_is_already_present(number, tab, i) == 0)
			return (NULL);
		tab[i] = number;
		i++;
	}
	return (tab);
}

t_stack_list	*ft_generate_stack_element(int number)
{
	t_stack_list	*element;

	element = ft_calloc(sizeof(t_stack_list), 1);
	element->data = number;
	element->index_sorted = 0;
	element->bloc = 0;
	element->next = NULL;
	element->previous = NULL;
	return (element);
}

t_stack_list	**ft_generate_full_stack(int *tab, int argc)
{
	int				i;
	t_stack_list	**stack;
	t_stack_list	*before;
	t_stack_list	*element;

	i = 2;
	stack = ft_calloc(sizeof(t_stack_list *), argc - 1);
	before = ft_generate_stack_element(tab[0]);
	element = ft_generate_stack_element(tab[1]);
	*stack = before;
	before->next = element;
	element->previous = before;
	while (i < argc - 1)
	{
		before = element;
		element = ft_generate_stack_element(tab[i]);
		element->previous = before;
		before->next = element;
		i++;
	}
	return (stack);
}

t_stack_list	**ft_generate_empty_stack(int argc)
{
	t_stack_list	**stack;

	stack = ft_calloc(sizeof(t_stack_list *), argc - 1);
	return (stack);
}
