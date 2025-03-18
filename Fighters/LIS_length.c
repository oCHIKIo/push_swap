/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:06:34 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 00:29:49 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	initialize_tabs(long int arr[][6666], t_list *node, int size)
{
	t_list	*current;
	int		x;

	current = node;
	x = 0;
	while (1)
	{
		arr[0][x++] = *current->content;
		current = current->next;
		if (current == node)
			break ;
	}
	x = 0;
	while (x < size)
		arr[1][x++] = LONG_MAX;
}

void	fill_second_array(long int arr[][6666], int node_size)
{
	int	x;
	int	y;

	x = 0;
	while (x < node_size)
	{
		y = 0;
		while (y < node_size)
		{
			if (arr[1][y] > arr[0][x])
			{
				arr[1][y] = arr[0][x];
				break ;
			}
			y++;
		}
		x++;
	}
}

void	hunt_for_lis_in_second_array(long int arr_2[], int *lis, int node_size)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < node_size)
	{
		if (arr_2[j] != LONG_MAX)
			i++;
		j++;
	}
	if (i > *lis)
		*lis = i;
}

int	lis_length_hunter(t_list *node)
{
	int			*lis;
	long int	arr[2][6666];
	int			i;
	int			node_size;

	i = 0;
	lis = &i;
	node_size = ft_lstsize(node);
	initialize_tabs(arr, node, 6666);
	fill_second_array(arr, node_size);
	hunt_for_lis_in_second_array(arr[1], lis, node_size);
	return (*lis);
	(void)arr;
}

int	lis_length(t_list *stack)
{
	t_list	*current;
	int		lis_length;
	int		tmp;
	int		cr7_is_the_goat;

	if (!stack)
		return (0);
	cr7_is_the_goat = 7;
	lis_length = 1;
	current = stack;
	while (cr7_is_the_goat)
	{
		tmp = lis_length_hunter(current);
		if (tmp > lis_length)
			lis_length = tmp;
		current = current->next;
		if (current == stack)
			break ;
	}
	return (lis_length);
}
