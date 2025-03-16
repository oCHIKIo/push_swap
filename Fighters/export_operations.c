/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:35:05 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/12 01:05:20 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		fake_abs(int value)
{
	if (value <= 0)
		return (-value);
	else
		return (value);
}
int	min_value(int value_1, int value_2)
{
	if (value_1 <= value_2)
		return (value_1);
	else
		return (value_2);
}
void	operations_functions(t_value *data, int x_arr[])
{
	while (--x_arr[rrr] >= 0)
		operation_rrotate_double(data);
	while (--x_arr[rr] >= 0)
		operation_rotate_double(data);
	while (--x_arr[ra] >= 0)
		operation_rotate_single(&data->stack_a, ra);
	while (--x_arr[rb] >= 0)
		operation_rotate_single(&data->stack_b, rb);
	while (--x_arr[rra] >= 0)
		operation_rrotate_single(&data->stack_a, rra);
	while (--x_arr[rrb] >= 0)
		operation_rrotate_single(&data->stack_b, rrb);
	operation_push(data, b_to_a);
}
void	export_operations(t_value *data, int moves_needed[])
{
	int	x_arr[7];
	int	x;

	x = nothing_here;
	while (x < 7)
		x_arr[x++] = nothing_here;
	if (moves_needed[0] > 0 && moves_needed[1] > 0)
		x_arr[rrr] = min_value(moves_needed[0], moves_needed[1]);
	else if (moves_needed[0] < 0 && moves_needed[1] < 0)
		x_arr[rr] = min_value(fake_abs(moves_needed[0]), fake_abs(moves_needed[1]));
	if (moves_needed[0] < 0)
		x_arr[rb] = fake_abs(moves_needed[0]) - x_arr[rr];
	else if (moves_needed[0] > 0)
		x_arr[rrb] = moves_needed[0] - x_arr[rrr];
	if (moves_needed[1] < 0)
		x_arr[ra] = fake_abs(moves_needed[1]) - x_arr[rr];
	else if (moves_needed[1] > 0)
		x_arr[rra] = moves_needed[1] - x_arr[rrr];
	operations_functions(data, x_arr);
}