/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_need_some_moves.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:11:04 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/17 17:30:10 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	find_optimal_forward_moves_stack_b(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	t_list	*current;
	int		x;

	x = 0;
	current = node;
	while (1)
	{
		if (current == data->stack_b)
			break ;
		x++;
		current = current->next;
	}
	if (x < *tmp_max_possible)
	{
		tmp_moves_needed[0] = x; /* stores the number of rb*/
		*tmp_max_possible = x;
	}
}
void	find_optimal_backward_moves_stack_b(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	t_list	*current;
	int		x;

	x = 0;
	current = node;
	while (1)
	{
		if (current == data->stack_b)
			break ;
		x--;
		current = current->prev;
	}
	if (-x < *tmp_max_possible)
	{
		tmp_moves_needed[0] = x;
		*tmp_max_possible = -x;
	}
}
void	moves_we_need_for_stack_b(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_max_possible)
{
	*tmp_max_possible = INT_MAX;
	if (!data || !node || !data->stack_b)
		return ;
	find_optimal_forward_moves_stack_b(data, node, tmp_moves_needed, tmp_max_possible);
	find_optimal_backward_moves_stack_b(data, node, tmp_moves_needed, tmp_max_possible);
	if (data->stack_a && data->stack_a != data->stack_a->next)
		*tmp_max_possible = INT_MAX;
}