/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:19 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/05 14:12:08 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# include "Libft/libft.h"

# include "ps_lecture/lecture.h"
# include "ps_operations/operations.h"

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
int			ft_distance_100(t_stack_list **stack_a, int *bool);
void 		ft_send_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, int *count);
int			ft_get_max_in_bloc_10(t_stack_list **stack_b, int working_bloc);
void		ft_cut_bloc_10_to_5_in_b(t_stack_list **stack_b, t_stack_list **stack_a, int *count);
void		ft_sort_3_in_a_100(t_stack_list **stack_a, t_stack_list **stack_b, int *count);
void		ft_sort_3_in_full_a(t_stack_list **stack_a, t_stack_list **stack_b, int *count);
void		ft_sort_5_in_full_a(t_stack_list **stack_a, t_stack_list **stack_b, int *count);
void		ft_send_3_from_b_in_a_100(t_stack_list **stack_a, t_stack_list **stack_b, int *count, int working_bloc);
void		ft_sort_5_in_full_b(t_stack_list **stack_a, t_stack_list **stack_b, int *count);


#endif
