/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre-sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:49:09 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 02:10:54 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_in_lis_arr(t_list *node, int *lis_arr)
{
	int	x;

	x = 0;
	while (lis_arr[x] != INT_MAX)
	{
		if (node && lis_arr[x] == *node->content)
			return (1);
		x++;
	}
	(void)node;
	return (0);
}

int	stack_a_is_ordered(t_list *stack)
{
	t_list	*current;
	int		found_rev;

	found_rev = 0;
	current = stack;
	if (current == current->next)
		return (1);
	while (1)
	{
		if (*current->content > *current->next->content)
			found_rev += 1;
		current = current->next;
		if (current == stack)
			break ;
	}
	if (found_rev == 1)
		return (1);
	else
		return (0);
}

int	stack_a_is_reversed(t_list *stack)
{
	t_list	*current;
	int		found_rev;

	found_rev = 0;
	current = stack;
	if (current == current->next)
		return (0);
	while (1)
	{
		if (*current->content < *current->next->content)
			found_rev += 1;
		current = current->next;
		if (current == stack)
			break ;
	}
	if (found_rev == 1)
		return (1);
	else
		return (0);
}

void	pre_sort_over_50(t_value *data, int *lis_arr)
{
	int	x;

	x = ft_lstsize(data->stack_a);
	if (!stack_a_is_ordered(data->stack_a))
	{
		while (x > 0)
		{
			if (data && data->stack_a && is_in_lis_arr(data->stack_a, lis_arr))
				operation_rotate_single(&data->stack_a, ra);
			else if (data && data->stack_a
				&& *data->stack_a->content > data->devider_arr[0])
			{
				operation_push(data, a_to_b);
			}
			else
			{
				operation_push(data, a_to_b);
				operation_rotate_single(&data->stack_b, rb);
			}
			x--;
		}
	}
}

void	pre_sort_stack_a(t_value *data, int *lis_arr)
{
	if (ft_lstsize(data->stack_a) <= 50)
	{
		while (!stack_a_is_ordered(data->stack_a))
		{
			if (!is_in_lis_arr(data->stack_a, lis_arr))
				operation_push(data, a_to_b);
			else
				operation_rotate_single(&data->stack_a, ra);
		}
		return ;
	}
	else
		pre_sort_over_50(data, lis_arr);
}
