/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:13:49 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 00:30:55 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_rotate_single(t_list **stack, enum t_operation operation)
{
	if (!*stack || !(*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (operation != 0)
		operation_print(operation);
}

void	operation_rrotate_single(t_list **stack, enum t_operation operation)
{
	if (!*stack || !(*stack)->prev)
		return ;
	*stack = (*stack)->prev;
	if (operation != 0)
		operation_print(operation);
}

void	operation_rotate_double(t_value *data)
{
	operation_rotate_single(&data->stack_a, 0);
	operation_rotate_single(&data->stack_b, 0);
	operation_print(rr);
}

void	operation_rrotate_double(t_value *data)
{
	operation_rrotate_single(&data->stack_a, 0);
	operation_rrotate_single(&data->stack_b, 0);
	operation_print(rrr);
}
