/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:28:19 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/12 14:08:41 by vde-leus         ###   ########.fr       */
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
# include "algo_10_100/algo_10_100.h"
# include "algo_100_500/algo_100_500.h"
# include "algo_5_10/algo_5_10.h"
# include "algo_3_5/algo_3_5.h"
# include "bonus/bonus.h"
# include "utils_0_3/utils_0_3.h"

void			ft_opti_display(t_instruction_list *instruction_list);
void			ft_free(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int *tab);
void			ft_operation(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int argc);

#endif
