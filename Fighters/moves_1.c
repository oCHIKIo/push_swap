/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:48:20 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/12 13:21:10 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	operation_print(enum t_operation operation)
{
	char	*operations[12];

	operations[nothing_here] = NULL;
	operations[rr] = "rr";
	operations[rrr] = "rrr";
	operations[ra] = "ra";
	operations[rb] = "rb";
	operations[rra] = "rra";
	operations[rrb] = "rrb";
	operations[sa] = "sa";
	operations[sb] = "sb";
	operations[ss] = "ss";
	operations[pa] = "pa";
	operations[pb] = "pb";
	if (operations[operation] != NULL)
	{
		write(1, operations[operation],
			ft_strlen(operations[operation]));
		write(1, "\n", 1);
	}
}
void	operation_swap_single(t_list *stack, enum t_operation operation)
{
	if (stack && stack->next)
		swap_node_data(stack, stack->next);
	operation_print(operation);
}
void	operation_swap_double(t_value *data)
{
	if (data->stack_a && data->stack_a->next && data->stack_b
		&& data->stack_b->next)
	{
		swap_node_data(data->stack_a, data->stack_a->next);
		swap_node_data(data->stack_b, data->stack_b->next);
	}
	operation_print(ss);
}

void	operation_push(t_value *data, enum t_direction direction)
{
	data->nodes_to_push_b_to_a--;
	send_top_node(data, direction);
	if (direction == a_to_b)
		operation_print(pb);
	else if (direction == b_to_a)
		operation_print(pa);
}