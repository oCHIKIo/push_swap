/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_got_ur_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:51:15 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/21 03:13:17 by bchiki           ###   ########.fr       */
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

int	check_digits(const char *str, int x, int sign)
{
	long long	res;
	int			nerd;

	res = 0;
	nerd = 0;
	while (ft_isdigit(str[x]))
	{
		nerd++;
		if (nerd > 10)
			return (1);
		res = res * 10 + (str[x] - '0');
		if (sign == 1 && res > INT_MAX)
			return (1);
		if (res > (long long)INT_MAX + 1)
			return (1);
		x++;
	}
	return (str[x] != '\0');
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
