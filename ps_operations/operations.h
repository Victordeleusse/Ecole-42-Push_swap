/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:05:02 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/04 10:06:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

/* swap between the first and the second element of a stack */
void			ft_swap_a(t_stack_list **stack, int *count);
void			ft_swap_b(t_stack_list **stack, int *count);
void			ft_double_swap(t_stack_list **stack1, t_stack_list **stack2, \
			int *count);

void			ft_push_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, \
			int *count);
void			ft_push_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, \
			int *count);
/* extraction of the first element of a stack */
t_stack_list	*ft_pop_first(t_stack_list **stack);
/* extraction of the last element of a stack */
t_stack_list	*ft_pop_last(t_stack_list **stack);
/* adding an element on the top of a stack */
void			ft_add_first(t_stack_list **stack, t_stack_list *element);
/* adding an element to the bottom of a stack */
void			ft_add_last(t_stack_list **stack, t_stack_list *element);
/* 'rotation' of the stack -> first elem becoming last */
void			ft_rotate_a(t_stack_list **stack_a, int *count);
void			ft_rotate_b(t_stack_list **stack_b, int *count);
void			ft_double_rotate(t_stack_list **stack_a, \
			t_stack_list **stack_b, int *count);
/* 'inverse rotation' of the stack -> last elem becoming first */
void			ft_reverse_rotate_a(t_stack_list **stack_a, int *count);
void			ft_reverse_rotate_b(t_stack_list **stack_b, int *count);
void			ft_double_reverse_rotate(t_stack_list **stack_a, \
			t_stack_list **stack_b, int *count);

/////////////////////////////// TRI A BULLE.C////////////////////////////////

int				*ft_sort(int *tab, int argc);
int				*ft_tab_copy(int *tab, int argc);
int				ft_get_mediane_value(int *tab, int size_tab);
int				ft_get_mediane_index(t_stack_list **stack);
void			ft_get_index_sorted(t_stack_list **stack_a, int *tab, int argc);

#endif