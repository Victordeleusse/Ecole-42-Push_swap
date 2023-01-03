/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:19 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/03 18:04:49 by vde-leus         ###   ########.fr       */
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
	int					index_sorted;
	int					bloc;
	struct s_stack_list	*previous;
	struct s_stack_list	*next;
}t_stack_list;

int				*ft_generate_tab_int(int argc, char **argv);
t_stack_list	*ft_generate_stack_element(int number);
t_stack_list	**ft_generate_full_stack(int *tab, int argc);
t_stack_list	**ft_generate_empty_stack(int argc);

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

/////////////////////////////// ERROR.C////////////////////////////////

int				ft_is_int(int number, char *str, int count);
int				ft_is_already_present(int number, int *tab, int taille);

/////////////////////////////// TRI A BULLE.C////////////////////////////////

int				*ft_sort(int *tab, int argc);
int				*ft_tab_copy(int *tab, int argc);
int				ft_get_mediane_value(int *tab, int size_tab);
int				ft_get_mediane_index(t_stack_list **stack);
void			ft_get_index_sorted(t_stack_list **stack_a, int *tab, int argc);

/////////////////////////////// UTILS_v0.C////////////////////////////////

int				ft_get_stack_size(t_stack_list **tab);
int				ft_get_index_max(t_stack_list **stack);
int				ft_get_index_min(t_stack_list **stack);
int				ft_get_mediane_index(t_stack_list **stack);
int				ft_get_mediane_position(t_stack_list **stack);

/////////////////////////////// UTILS_v3.C////////////////////////////////	

int				ft_get_pos_min(t_stack_list **stack_a);
void			ft_case_beginning(t_stack_list **stack_a, int *count);
void			ft_case_end(t_stack_list **stack_a, int *count, int size_stack_a);
void			ft_case_middle(t_stack_list **stack_a, int *count, int size_stack_a);
void			ft_sort_3(t_stack_list **stack_a, int *count, int size_stack_a);

/////////////////////////////// UTILS_v5.C////////////////////////////////

int				ft_already_sort_5(t_stack_list **stack);
int				ft_get_distance(t_stack_list **stack, int mediane_index);
void			ft_prepare_stack_4(t_stack_list **stack1, \
					t_stack_list **stack2, int *count, int mediane_index);
void			ft_prepare_stack_3(t_stack_list **stack1, \
					t_stack_list **stack2, int *count, int mediane_index);
void	ft_prepare_stack_3_bis(t_stack_list **stack1, t_stack_list **stack2, \
					int *count, int mediane_index);
void			ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, int *count);

/////////////////////////////// UTILS_v10.C////////////////////////////////

// int				ft_get_distance_multibloc(t_stack_list **stack, int mediane_index, int bloc);
// int				ft_prepare_stack_4_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index);
// void			ft_prepare_stack_3_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index);
// void			ft_prepare_stack_3_bis_multibloc(t_stack_list **stack1, t_stack_list **stack2, int *count, int mediane_index);
// void			ft_sort_10(t_stack_list **stack1, t_stack_list **stack2, int *count);

/////////////////////////////// UTILS_v10.C////////////////////////////////

int			ft_distance_10(t_stack_list **stack, int size_stack_init);
void		ft_exit_case_10(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int size_stack, int size_stack_init);
void		ft_separate_stack(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int size_stack_init);
int			ft_distance_max_in_b(t_stack_list **stack_b);
void		ft_restore_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, int *count);

/////////////////////////////// UTILS_v100.C////////////////////////////////

void		ft_init_bloc(t_stack_list **stack_a, int size_init);
int			ft_is_bloc_present(t_stack_list **stack_a, int bloc_searched);
int			ft_distance_min_impair(t_stack_list **stack_a);
int			ft_distance_min_pair(t_stack_list **stack_a);

#endif
