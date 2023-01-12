/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:24:59 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/12 16:03:06 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

////////////////////// LECTURE_BONUS.C //////////////////////

char				**ft_generate_instruction_tab(void);
int					ft_order_is_available(char **instruction_tab, char *order);
t_instruction_list	*ft_generate_instruction_bloc(char **instruction_tab, \
				char *order);
t_instruction_list	**ft_generate_instruction_list(int fd);
int					main(int argc, char **argv);

////////////////////// MAIN.C //////////////////////

void				ft_operation_bonus_swap_push_rev(t_instruction_list *begin, \
				t_instruction_list *instruction_lst_annexe, \
				t_stack_list **stack_a, t_stack_list **stack_b);
void				ft_operation_bonus_rotate(\
				t_instruction_list **instruction_lst, \
				t_stack_list **stack_a, t_stack_list **stack_b);

#endif