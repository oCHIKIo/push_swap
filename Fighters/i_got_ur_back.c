/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_got_ur_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:51:15 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 00:22:53 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (2);
}

void	del(void *nil)
{
	(void)nil;
}

int	free_everything(t_value *data, int *input_arr, int *lis_arr, char **av)
{
	int	x;

	if (data)
	{
		if (data->stack_a)
			ft_lstclear(&data->stack_a);
		if (data->stack_b)
			ft_lstclear(&data->stack_b);
		free(data);
	}
	x = 0;
	if (av)
	{
		while (av[x])
		{
			free(av[x]);
			x++;
		}
		free(av);
	}
	if (input_arr)
		free(input_arr);
	if (lis_arr)
		free(lis_arr);
	return (255);
}
