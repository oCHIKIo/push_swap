/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_devider.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:05:00 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/12 01:03:04 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void	devider_value(t_value *data, int tmp_tab[], int size)
{
	data->devider_arr[0] = tmp_tab[size / 2];
}
void	sort_just_for_devider(int size, int tmp_tab[])
{
	int	swap_occurred;
	int	end;
	int	x;

	end = size - 1;
	while (end > 0)
	{
		x = 0;
		swap_occurred = 0;
		while (x < end)
		{
			if (tmp_tab[x] > tmp_tab[x + 1])
			{
				swap(&tmp_tab[x], &tmp_tab[x + 1]);
				swap_occurred = 1;
			}
			x++;
		}
		if (swap_occurred == 0)
			break ;
	}
}
void	calculate_devider(t_value *data, int *input_arr)
{
	int	x;
	int	size;
	int	tmp_tab[6666];

	x = 0;
	size = ft_lstsize(data->stack_a);
	while (x < size)
	{
		tmp_tab[x] = input_arr[x];
		x++;
	}
	sort_just_for_devider(size, tmp_tab);
	devider_value(data, tmp_tab, size);
}
