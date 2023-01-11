/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100_500.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:28:06 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 10:49:53 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_100_500_H
# define ALGO_100_500_H

void			ft_start_impair(t_stack_list *begin_a, \
	int mediane_index, int size_init);
void			ft_start_pair(t_stack_list *begin_a, \
	int mediane_index);
void			ft_init_bloc_500(t_stack_list **stack_a, int size_init);
int				ft_is_bloc_present_500(t_stack_list **stack_a, \
			int bloc_searched);
void			ft_calculate_dist_min_impair(t_stack_list **begin_a, \
		t_stack_list **end_a, int *dist_begin_impair, int *dist_end_impair);
int				ft_distance_min_impair_500(t_stack_list **stack_a);
int				ft_distance_min_pair_500(t_stack_list **stack_a);
int				ft_distance_500(t_stack_list **stack_a, int *bool);
void			ft_send_a_to_b_500(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);
int				ft_get_max_in_bloc_25(t_stack_list **stack, int working_bloc);
void			ft_send_max_in_bloc_25_from_b_to_a(t_stack_list **stack_a, \
		t_stack_list **stack_b, int index_max, \
		t_instruction_list **instruction_list);
void			ft_send_max_part_sup(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list, \
		int *distance);
void			ft_send_max_part_inf(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list, \
		int *distance);
void			ft_send_max_from_b_to_a_500(t_stack_list **stack_a, \
		t_stack_list **stack_b, int working_bloc, \
		t_instruction_list **instruction_list);
void			ft_send_b_to_a_500(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);


#endif