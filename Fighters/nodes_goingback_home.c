/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_goingback_home.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:50:27 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/14 11:44:51 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_variables(int moves_needed[], int tmp_moves_needed[],
		int *lowest_move_cost)
{
	moves_needed[0] = 0;
	moves_needed[1] = 0;
	tmp_moves_needed[0] = 0;
	tmp_moves_needed[1] = 0;
	*lowest_move_cost = INT_MAX;
}
void	update_variables(int *lowest_move_cost, int *tmp_lowest_move_cost,
		int moves_needed[], int tmp_moves_needed[])
{
	if (*tmp_lowest_move_cost < *lowest_move_cost)
	{
		*lowest_move_cost = *tmp_lowest_move_cost;
		moves_needed[0] = tmp_moves_needed[0];
		moves_needed[1] = tmp_moves_needed[1];
	}
	tmp_moves_needed[0] = 0;
	tmp_moves_needed[1] = 0;
	*tmp_lowest_move_cost = INT_MAX;
}
void	going_back_home(t_value *data)
{
	t_list	*current;
	int		moves_needed[2];
	int		tmp_moves_needed[2];
	int		max_possible;
	int		tmp_max_possible;

	if (!data || !data->stack_b)
		return ;
	initialize_variables(moves_needed, tmp_moves_needed, &max_possible);
	current = data->stack_b;
	while (1)
	{
		tmp_moves_needed[0] = 0;
		tmp_moves_needed[1] = 0;
		moves_we_need_for_stack_b(data, current, tmp_moves_needed,
			&tmp_max_possible);
		moves_we_need_for_stack_a(data, current, tmp_moves_needed,
			&tmp_max_possible);
		update_variables(&max_possible, &tmp_max_possible, moves_needed,
			tmp_moves_needed);
		if (max_possible == 0 || current->next == data->stack_b)
			break ;
		current = current->next;
	}
	export_operations(data, moves_needed);
}