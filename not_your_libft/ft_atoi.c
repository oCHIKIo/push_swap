/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:52:34 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/11 21:52:34 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	res;
	int			x;
	int			sign;

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
		return (0);
	return (res * sign);
}
