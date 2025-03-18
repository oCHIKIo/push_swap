/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_need_some_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:11 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 00:56:37 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	just_one_node_to_check_in_stack_b(t_value *data, int tmp_moves_needed[],
		int *tmp_max_possible)
{
	if ((!data->stack_a || (data->stack_a->next == data->stack_a)))
	{
		tmp_moves_needed[1] = 0;
		*tmp_max_possible = 0;
	}
}

int	should_break_here(t_list *current, int node_value)
{
	if ((*current->content < *current->prev->content
			&& *current->content < *current->next->content)
		&& ((*current->content < node_value
				&& *current->prev->content < node_value)
			|| (*current->content > node_value
				&& *current->prev->content > node_value)))
		return (1);
	if ((node_value < *current->content
			&& node_value > *current->prev->content))
		return (1);
	return (0);
}

void	find_optimal_backward_moves_stack_a(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	t_list	*current;
	int		x;
	int		node_value;

	node_value = *node->content;
	x = 0;
	current = data->stack_a;
	while (1)
	{
		if (should_break_here(current, node_value))
			break ;
		x--;
		current = current->prev;
		if (current == data->stack_a)
			break ;
	}
	if (-x < *tmp_max_possible)
	{
		tmp_moves_needed[1] = -x;
		*tmp_max_possible = -x;
	}
}

void	find_optimal_forward_moves_stack_a(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	t_list	*current;
	int		x;
	int		node_value;

	x = 0;
	current = data->stack_a;
	node_value = *node->content;
	just_one_node_to_check_in_stack_b(data, tmp_moves_needed, tmp_max_possible);
	while (1)
	{
		if (should_break_here(current, node_value))
			break ;
		x++;
		current = current->next;
		if (current == data->stack_a)
			break ;
	}
	if (x < *tmp_max_possible)
	{
		tmp_moves_needed[1] = -x;
		*tmp_max_possible = x;
	}
}

void	moves_we_need_for_stack_a(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	if (!data || !node || !data->stack_a)
		return ;
	find_optimal_forward_moves_stack_a(data, node, tmp_moves_needed,
		tmp_max_possible);
	find_optimal_backward_moves_stack_a(data, node, tmp_moves_needed,
		tmp_max_possible);
	*tmp_max_possible = 0;
	if (tmp_moves_needed[0] > 0)
		*tmp_max_possible += tmp_moves_needed[0];
	else
		*tmp_max_possible -= tmp_moves_needed[0];
	if (tmp_moves_needed[1] > 0)
		*tmp_max_possible += tmp_moves_needed[1];
	else
		*tmp_max_possible -= tmp_moves_needed[1];
}
