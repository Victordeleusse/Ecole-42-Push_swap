/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:22:59 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/16 15:04:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_give_instruction(char a, char b, char c)
{
	char	*instruction;

	instruction = ft_calloc(sizeof(char), 4);
	instruction[0] = a;
	instruction[1] = b;
	instruction[2] = c;
	return (instruction);
}

char	**ft_generate_instruction_tab(void)
{
	char	**instruction_tab;

	instruction_tab = ft_calloc(sizeof(char *), 12);
	if (!instruction_tab)
		return (NULL);
	instruction_tab[0] = ft_give_instruction('r', 'a', '\0');
	instruction_tab[1] = ft_give_instruction('r', 'b', '\0');
	instruction_tab[2] = ft_give_instruction('r', 'r', '\0');
	instruction_tab[3] = ft_give_instruction('s', 'a', '\0');
	instruction_tab[4] = ft_give_instruction('s', 'b', '\0');
	instruction_tab[5] = ft_give_instruction('s', 's', '\0');
	instruction_tab[6] = ft_give_instruction('r', 'r', 'a');
	instruction_tab[7] = ft_give_instruction('r', 'r', 'b');
	instruction_tab[8] = ft_give_instruction('r', 'r', 'r');
	instruction_tab[9] = ft_give_instruction('p', 'a', '\0');
	instruction_tab[10] = ft_give_instruction('p', 'b', '\0');
	instruction_tab[11] = 0;
	return (instruction_tab);
}

int	ft_order_is_available(char **instruction_tab, char *order)
{
	int		count;
	size_t	order_len;

	order_len = ft_strlen(order);
	count = 0;
	while (instruction_tab[count])
	{
		if ((ft_strncmp(instruction_tab[count], order, order_len - 1) == 0) && \
			ft_strlen(instruction_tab[count]) == order_len - 1)
			return (1);
		count++;
	}
	return (0);
}

t_instruction_list	*ft_generate_instruction_bloc(char **instruction_tab, \
		char *order)
{
	t_instruction_list	*instruction_bloc;
	int					bool;
	size_t				len_order;
	size_t				i;

	bool = ft_order_is_available(instruction_tab, order);
	if (bool == 0)
		return (NULL);
	instruction_bloc = ft_calloc(sizeof(t_instruction_list), 1);
	if (!instruction_bloc)
		return (NULL);
	instruction_bloc->instruction = ft_calloc(sizeof(order), 1);
	len_order = ft_strlen(order);
	i = 0;
	while (i < len_order)
	{
		instruction_bloc->instruction[i] = order[i];
		i++;
	}
	instruction_bloc->instruction[len_order - 1] = '\0';
	instruction_bloc->next = 0;
	return (instruction_bloc);
}

t_instruction_list	*ft_generate_instruction_list(int fd)
{
	t_instruction_list	*instruction_lst;
	t_instruction_list	*begin;
	t_instruction_list	*next_bloc;
	char				*order;
	char				**instruction_tab;

	instruction_tab = ft_generate_instruction_tab();
	order = get_next_line(fd);
	instruction_lst = ft_generate_instruction_bloc(instruction_tab, order);
	if (!instruction_tab || !instruction_lst || order == NULL)
		return (NULL);
	free (order);
	begin = instruction_lst;
	while (1)
	{
		order = get_next_line(fd);
		if (order == NULL)
			break ;
		next_bloc = ft_generate_instruction_bloc(instruction_tab, order);
		free (order);
		begin->next = next_bloc;
		begin = next_bloc;
	}
	ft_free_instruction_tab(instruction_tab);
	return (instruction_lst);
}
