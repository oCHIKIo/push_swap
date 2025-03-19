/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understanding_deciphering.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:33:29 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/19 01:51:34 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	there_is_sign(char x)
{
	return (x == '+' || x == '-');
}

int	is_beyond_int_limits(const char *str)
{
	t_nbr	nbr;

	nbr.x = 0;
	nbr.sign = 1;
	nbr.res = 0;
	nbr.digit_count = 0;
	while (str[nbr.x] == ' ' || (str[nbr.x] >= 9 && str[nbr.x] <= 13))
		nbr.x++;
	if (str[nbr.x] == '-' || str[nbr.x] == '+')
	{
		if (str[nbr.x++] == '-')
			nbr.sign *= -1;
	}
	while (ft_isdigit(str[nbr.x]))
	{
		nbr.digit_count++;
		if (nbr.digit_count > 10)
			return (1);
		nbr.res = nbr.res * 10 + (str[nbr.x++] - '0');
		if ((nbr.sign == 1 && nbr.res > INT_MAX) || (nbr.sign == -1
				&& nbr.res > (long long)INT_MAX + 1))
			return (1);
	}
	return (0);
}

int	is_well_formed_number(char *num)
{
	int	x;

	x = 0;
	while (num[x] == ' ' || (num[x] >= 9 && num[x] <= 13))
		x++;
	if (num[x] == '\0')
		return (0);
	while (num[x])
	{
		if (!ft_isdigit(num[x]) && !there_is_sign(num[x]))
			return (0);
		if (there_is_sign(num[x]) && (!num[x + 1] || there_is_sign(num[x + 1])
				|| (x != 0 && num[x - 1] && num[x - 1] != ' ')))
			return (0);
		x++;
	}
	if (is_beyond_int_limits(num))
		return (0);
	return (1);
}

int	understanding_deciphering(char **av, int ac)
{
	int	x;
	int	y;
	int	arr[10000];

	if (ac == 2 && av[1][0] == '\0')
		return (0);
	x = 0;
	while (av[++x])
	{
		if (!is_well_formed_number(av[x]))
			return (0);
		arr[x - 1] = ft_atoi(av[x]);
	}
	x = 0;
	while (x < ac - 1)
	{
		if (arr[x] > INT_MAX || arr[x] < INT_MIN)
			return (0);
		y = -1;
		while (++y < ac - 1)
			if ((arr[x] == arr[y]) && (x != y))
				return (0);
		x++;
	}
	return (1);
}
