/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_10_100.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:59:58 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/10 18:02:45 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_10_100_H
# define ALGO_10_100_H

void			ft_init_bloc_pair_100(t_stack_list *begin_a, int mediane_index);
void			ft_init_bloc_impair_100(t_stack_list *begin_a, \
			int mediane_index);
void			ft_init_bloc(t_stack_list **stack_a, int size_init);
int				ft_is_bloc_present(t_stack_list **stack_a, int bloc_searched);
void			ft_init_dist_impair_100(t_stack_list **stack_a, \
			int *dist_begin_impair, int *dist_end_impair, int *bloc_impair);
t_stack_list	*ft_last_elem_stack(t_stack_list **stack_a, \
	int *dist_end_impair);
int				ft_distance_min_impair(t_stack_list **stack_a);
void			ft_init_dist_pair_100(t_stack_list **stack_a, \
	int *dist_begin_pair, int *dist_end_pair, int *bloc_pair);
int				ft_distance_min_pair(t_stack_list **stack_a);
int				ft_calc_dist_min(int dist_min_pair, int dist_min_impair, \
	int size_stack, int *bool);
int				ft_distance_100(t_stack_list **stack_a, int *bool);
void			ft_send_a_to_b_from_top(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_send_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, \
		t_instruction_list **instruction_list);
int				ft_get_max_in_bloc_10(t_stack_list **stack_b, int working_bloc);
void			ft_finish_cuting_in_half(t_stack_list **stack_b, \
		t_stack_list **stack_a, t_instruction_list **instruction_list, \
		int nb_rotate);
void			ft_rotate_5_in_10(t_stack_list **stack_b, \
		t_instruction_list **instruction_list, int *nb_rotate);
void			ft_cut_bloc_10_to_5_in_b(t_stack_list **stack_b, \
		t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_sort_3_in_a_100_case_1(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_3_in_a_100_case_2(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_3_in_a_100_case_3(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_3_in_a_100_case_4(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_3_in_a_100(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_3_in_full_a(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_sort_5_in_big_5(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list, \
		int working_bloc);
void			ft_sort_5_in_full_a(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_send_3_test_1(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_send_3_exec_1(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_send_3_from_b_in_a_100(t_stack_list **stack_a, \
		t_stack_list **stack_b, int working_bloc, \
		t_instruction_list **instruction_list);
void			ft_sort_5_in_full_b(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);

#endif