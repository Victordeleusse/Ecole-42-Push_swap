/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:29:07 by vde-leus          #+#    #+#             */
/*   Updated: 2022/11/28 15:46:48 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list_l *lst)
{
	int		size;
	t_list_l	*begin;

	size = 0;
	begin = lst;
	while (begin)
	{
		size++;
		begin = begin->next;
	}
	return (size);
}
