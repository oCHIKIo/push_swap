/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:07:12 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/13 23:22:43 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	shortcut(int **lis_arr)
{
	*lis_arr = NULL;
}
void	initialize_tabs_both(t_list *node, int tab[][6666])
{
	t_list	*current;
	int		x;

	x = 0;
	current = node;
	while (x < 6666)
	{
		tab[1][x] = 1;
		tab[2][x] = -1;
		if (current)
			tab[0][x] = *current->content;
		else
			tab[0][x] = INT_MAX;
		current = current->next;
		x++;
		if (current == node)
			break ;
	}
	while (x < 6666)
	{
		tab[1][x] = 0;
		tab[2][x] = -1;
		tab[0][x] = INT_MAX;
		x++;
	}
}
void	LIS_filler(int *lis_tab, int tab[][6666], int lis, int size)
{
	int	x;
	int	lis_index;

	lis_index = -1;
	x = size - 1;
	while (tab[1][x] != lis)
		x--;
	lis_index = x;
	x = lis - 1;
	while (lis_index != -1)
	{
		lis_tab[x] = tab[0][lis_index];
		lis_index = tab[2][lis_index];
		x--;
	}
	lis_tab[lis] = INT_MAX;
}
int	LIS_hunter(int tab[][6666], int lis_len)
{
	int	x[3];

	x[0] = 1;
	x[2] = 0;
	while (tab[1][x[0]] != 0)
	{
		x[1] = 0;
		while (x[1] < x[0])
		{
			if (tab[0][x[0]] > tab[0][x[1]])
			{
				x[2] = tab[1][x[1]] + 1;
				if (x[2] > tab[1][x[0]])
				{
					tab[1][x[0]] = x[2];
					tab[2][x[0]] = x[1];
				}
				if (x[2] == lis_len)
					return (1);
			}
			x[1]++;
		}
		x[0]++;
	}
	return (0);
}
int	LIS_arr(t_list *stack_a, int **lis_arr, t_value *data)
{
	t_list	*current;
	int		temp_arr[3][6666];
	int		lis_len;

	if (!stack_a)
		return (shortcut(lis_arr), -1);
	lis_len = LIS_length(stack_a);
	data->lis_length = lis_len;
	*lis_arr = (int *)ft_calloc(lis_len + 1, sizeof(int));
	if (!*lis_arr)
		return (0);
	current = stack_a;
	while (1)
	{
		current = current->next;
		initialize_tabs_both(current, temp_arr);
		if (LIS_hunter(temp_arr, lis_len))
		{
			LIS_filler(*lis_arr, temp_arr, lis_len, ft_lstsize(stack_a));
			break ;
		}
		if (current == stack_a)
			break ;
	}
	return (1);
}