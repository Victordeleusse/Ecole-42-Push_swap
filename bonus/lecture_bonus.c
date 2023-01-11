/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:22:59 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 18:52:11 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	**ft_generate_instruction_tab(void)
{
	char	**instruction_tab;

	instruction_tab = ft_calloc(sizeof(char *), 12);
	if (!instruction_tab)
		return (NULL);
	instruction_tab[0] = "ra";
	instruction_tab[1] = "rb";
	instruction_tab[2] = "rr";
	instruction_tab[3] = "sa";
	instruction_tab[4] = "sb";
	instruction_tab[5] = "ss";
	instruction_tab[6] = "rra";
	instruction_tab[7] = "rrb";
	instruction_tab[8] = "rrr";
	instruction_tab[9] = "pa";
	instruction_tab[10] = "pb";
	instruction_tab[11] = 0;
	return (instruction_tab);
}

int	ft_order_is_available(char **instruction_tab, char *order)
{
	int	count;
	int	order_len;

	order_len = ft_strlen(order);
	count = 0;
	while (instruction_tab[count])
	{
		if ((ft_strncmp(instruction_tab[count], order, order_len) == 0) && \
			ft_strlen(instruction_tab[count]) == order_len)
			return (1);
		count++;
	}
	return (0);
}

t_instruction_list	*ft_generate_instruction_bloc(char **instruction_tab, char *order)
{
	t_instruction_list	*bloc;

	if (ft_order_is_available(instruction_tab, order) == 0)
		return (NULL);
	bloc = ft_calloc(sizeof(t_instruction_list), 1);
	if (!bloc)
		return (NULL);
	bloc->instruction = order;
	bloc->next = NULL;
	return (bloc);
}

t_instruction_list	**ft_generate_instruction_list(int fd)
{
	t_instruction_list	**instruction_lst;
	t_instruction_list	*begin;
	t_instruction_list	*next_bloc;
	char				**instruction_tab;
	char				*order;

	instruction_tab = ft_generate_instruction_tab();
	if (!instruction_tab)
		return (NULL);
	instruction_lst = ft_calloc(sizeof(t_instruction_list *), 1);
	if (!instruction_lst)
		return (NULL);
	order = get_next_line(fd);
	if (order == NULL)
		return (NULL);
	begin = ft_generate_instruction_bloc(instruction_tab, order);
	*instruction_lst = begin;
	while (1)
	{
		order = get_next_line(fd);
		if (order == NULL)
			break ;
		next_bloc = ft_generate_instruction_bloc(instruction_tab, order);
		if (!next_bloc)
			return (NULL);
		begin->next = next_bloc;
		begin = next_bloc;
	}
}
