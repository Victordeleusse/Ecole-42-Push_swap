/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0_3.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:07:07 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/12 14:08:21 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_0_3_H
# define UTILS_0_3_H

/////////////////////////////// UTILS_v0.C////////////////////////////////

int				ft_get_stack_size(t_stack_list **tab);
int				ft_get_index_max(t_stack_list **stack);
int				ft_get_index_min(t_stack_list **stack);
int				ft_get_mediane_index(t_stack_list **stack);
int				ft_get_mediane_position(t_stack_list **stack);

/////////////////////////////// UTILS_v3.C////////////////////////////////	

int				ft_get_pos_min(t_stack_list **stack_a);
void			ft_case_beginning(t_stack_list **stack_a, \
					t_instruction_list **instruction_list);
void			ft_case_end(t_stack_list **stack_a, int size_stack_a, \
					t_instruction_list **instruction_list);
void			ft_case_middle(t_stack_list **stack_a, int size_stack_a, \
					t_instruction_list **instruction_list);
void			ft_sort_3(t_stack_list **stack_a, int size_stack_a, \
					t_instruction_list **instruction_list);

#endif