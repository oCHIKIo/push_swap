/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_wannabe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:11:40 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/12 12:38:06 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_node_data(t_list *node1, t_list *node2)
{
	int	*tmp;

	tmp = node1->content;
	node1->content = node2->content;
	node2->content = tmp;
}
void	remove_top_node(t_list **stack)
{
	if (!stack || !*stack)
		return ;
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
	}
}
void	send_top_node(t_value *data, enum t_direction direction)
{
	t_list	*tmp;

	if (direction == a_to_b && data->stack_a)
	{
		tmp = data->stack_a;
		remove_top_node(&data->stack_a);
		ft_lstadd_front(&data->stack_b, tmp);
	}
	else if (direction == b_to_a && data->stack_b)
	{
		tmp = data->stack_b;
		remove_top_node(&data->stack_b);
		ft_lstadd_front(&data->stack_a, tmp);
	}
}