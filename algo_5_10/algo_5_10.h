/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5_10.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:22:39 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/11 14:43:32 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_5_10_H
# define ALGO_5_10_H

int				ft_distance_10(t_stack_list **stack, int size_stack_init);
void			ft_exit_dist_1(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list);
void			ft_exit_dist_1_bis(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_exit_dist_2(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list);
void			ft_exit_dist_2_bis(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_exit_dist_3(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list);
void			ft_exit_dist_3_bis(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list);
void			ft_exit_case_10(t_stack_list **stack_a, t_stack_list **stack_b, \
		int size_stack_init, t_instruction_list **instruction_list);
void			ft_separate_stack(t_stack_list **stack_a, \
		t_stack_list **stack_b, \
		int size_stack_init, t_instruction_list **instruction_list);
int				ft_distance_max_in_b(t_stack_list **stack_b);
void			ft_restore_dist_0(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_dist_1(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_dist_2(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_dist_3(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_dist_4(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_dist_5(t_stack_list **stack_b, \
	t_stack_list **stack_a, t_instruction_list **instruction_list);
void			ft_restore_b_to_a(t_stack_list **stack_b, \
		t_stack_list **stack_a, t_instruction_list **instruction_list);

#endif