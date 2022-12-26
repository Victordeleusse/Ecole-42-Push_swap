/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:19 by vde-leus          #+#    #+#             */
/*   Updated: 2022/12/26 15:42:42 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "Libft/libft.h"

typedef struct s_stack_list
{
	int					data;
	struct s_stack_list	*previous;
	struct s_stack_list	*next;
}t_stack_list;

int				*ft_generate_tab_int(int argc, char **argv);
t_stack_list	*ft_generate_stack_element(int number);
t_stack_list	**ft_generate_full_stack(int *tab, int argc);
t_stack_list	**ft_generate_empty_stack(int argc);

/* swap between the first and the second element of a stack */
void			ft_swap(t_stack_list **stack, int *count);
void			ft_double_swap(t_stack_list **stack1, t_stack_list **stack2, \
			int *count);

void			ft_push(t_stack_list **stack1, t_stack_list **stack2, \
			int *count, int *size_stack_1);
/* extraction of the first element of a stack */
t_stack_list	*ft_pop_first(t_stack_list **stack);
/* extraction of the last element of a stack */
t_stack_list	*ft_pop_last(t_stack_list **stack);
/* adding an element on the top of a stack */
void			ft_add_first(t_stack_list **stack, t_stack_list *element);
/* adding an element to the bottom of a stack */
void			ft_add_last(t_stack_list **stack, t_stack_list *element);
/* 'rotation' of the stack -> first elem becoming last */
void			ft_rotate(t_stack_list **stack, int *count);
void			ft_double_rotate(t_stack_list **stack1, t_stack_list **stack2, \
			int *count);
/* 'inverse rotation' of the stack -> last elem becoming first */
void			ft_reverse_rotate(t_stack_list **stack, int *count);
void			ft_double_reverse_rotate(t_stack_list **stack1, \
			t_stack_list **stack2, int *count);

/////////////////////////////// ERROR.C////////////////////////////////

int				ft_is_int(int number, char *str, int count);
int				ft_is_already_present(int number, int *tab, int taille);

/////////////////////////////// TRI A BULLE.C////////////////////////////////

int				*ft_sort(int *tab, int argc);
int				*ft_tab_copy(int *tab, int argc);
int				ft_get_mediane(int *tab, int argc);
int				ft_stop_index(int *tab, int argc);

/////////////////////////////// UTILS.C////////////////////////////////

int				ft_get_pos_min(t_stack_list **stack_a);
void			ft_get_min_first(t_stack_list **stack_a, int *size_stack, \
			int *count);
void			ft_sort_stack_1(t_stack_list **stack_1, t_stack_list **stack_2, \
			int *count, int *size_stack_1);

#endif
