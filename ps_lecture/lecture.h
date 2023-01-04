/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:54:17 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/04 09:57:38 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LECTURE_H
# define LECTURE_H

typedef struct s_stack_list
{
	int					data;
	int					index_sorted;
	int					bloc;
	struct s_stack_list	*previous;
	struct s_stack_list	*next;
}t_stack_list;

int				*ft_generate_tab_int(int argc, char **argv);
t_stack_list	*ft_generate_stack_element(int number);
t_stack_list	**ft_generate_full_stack(int *tab, int argc);
t_stack_list	**ft_generate_empty_stack(int argc);

/////////////////////////////// ERROR.C////////////////////////////////

int				ft_is_int(int number, char *str, int count);
int				ft_is_already_present(int number, int *tab, int taille);

#endif