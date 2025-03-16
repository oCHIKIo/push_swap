/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:13:21 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/13 03:13:13 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	string_to_integer(int ac, char **av, int **input_arr)
{
	int	x;

	if (ac == 2 && av[1][0] == '\0')
		return (0);
	*input_arr = (int *)malloc(sizeof(int) * (ac - 1));
	if (*input_arr == 0)
		return (0);
	x = 0;
	while (++x <= (ac - 1))
		(*input_arr)[x - 1] = ft_atoi(av[x]);
	return (1);
}
int	create_stack(t_value **data, int *input_arr, int arr_size)
{
	int		x;
	t_list	*new_node;

	*data = (t_value *)malloc(sizeof(t_value));
	if (!*data)
		return (0);
	(*data)->stack_a = NULL;
	(*data)->stack_b = NULL;
	x = 0;
	while (x < arr_size)
	{
		new_node = ft_lstnew(&input_arr[x]);
		if (!new_node)
			return (0);
		ft_lstadd_back(&(*data)->stack_a, new_node);
		x++;
	}
	return (1);
}
