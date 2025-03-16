/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understanding_deciphering.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:33:29 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/13 01:38:31 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int there_is_sign(char x)
{
    int sign;
	sign = 0;
    sign |= (x == 43);
    sign |= (x == 45);
    return sign;
}
int	is_beyond_int_limits(const char *str)
{
	int			sign;
	long int	res;
	int			x;

	x = 0;
	sign = 1;
	res = 0;
	while (str[x] == ' ' || (str[x] >= 9 && str[x] <= 13))
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(str[x]))
		res = res * 10 + (str[x++] - '0');
	if (res * sign > INT_MAX || res * sign < INT_MIN)
		return (1);
	return (0);
}
int	is_well_formed_number(char *num)
{
	int	x;

	x = 0;
	while (num[x])
	{
		if (!ft_isdigit(num[x]) && (!there_is_sign(num[x])))
			return (0);
		if (there_is_sign(num[x]) && ((!(num[x + 1]) || there_is_sign(num[x
						+ 1])) || (x != 0 && (num[x - 1]))))
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
		arr[x - 1] = ft_atoi(av[x]);
	x = 0;
	while (++x < ac)
		if (!is_well_formed_number(av[x]))
			return (0);
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