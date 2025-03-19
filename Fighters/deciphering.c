/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deciphering.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:00:45 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/19 00:25:56 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#define INT_MAX_LEN 10

void	set_everything_null(char tmp_av[][11])
{
	int	x;
	int	y;

	x = 0;
	while (x < 6666)
	{
		y = 0;
		while (y < 11)
		{
			tmp_av[x][y] = '\0';
			y++;
		}
		x++;
	}
}

void	splitter(char *str, char tmp_av[][11], int *ac)
{
	char	**tmp_input_arr;
	int		x;

	tmp_input_arr = NULL;
	tmp_input_arr = ft_split(str, ' ');
	x = 0;
	while (tmp_input_arr[x])
	{
		if (ft_strlen(tmp_input_arr[x]) > INT_MAX_LEN)
		{
			print_error();
			while (tmp_input_arr[x])
				free(tmp_input_arr[x++]);
			free(tmp_input_arr);
			exit(1);
		}
		ft_strlcpy(tmp_av[*ac], tmp_input_arr[x],
			ft_strlen(tmp_input_arr[x]) + 1);
		(*ac)++;
		x++;
	}
	x = 0;
	while (tmp_input_arr[x])
		free(tmp_input_arr[x++]);
	free(tmp_input_arr);
}

bool	its_string(char *str)
{
	int	x;

	x = 0;
	while (str[x])
	{
		if (str[x] == 32 || str[x] == 9)
			return (true);
		x++;
	}
	return (false);
}

char	**update_av(int updated_ac, char tmp_av[][11])
{
	int		x;
	char	**new_av;

	new_av = ft_calloc(updated_ac + 2, sizeof(char *));
	if (!new_av)
		return (NULL);
	new_av[0] = ft_calloc(1, sizeof(char));
	if (!new_av)
		return (free(new_av), NULL);
	x = 1;
	while (x < updated_ac + 1)
	{
		new_av[x] = ft_calloc(ft_strlen(tmp_av[x - 1]) + 1, sizeof(char));
		if (!new_av)
		{
			while (x >= 0)
				free(new_av[x--]);
			return (free(new_av), NULL);
		}
		ft_strlcpy(new_av[x], tmp_av[x - 1], ft_strlen(tmp_av[x - 1]) + 1);
		x++;
	}
	new_av[x] = NULL;
	return (new_av);
}

char	**deciphering(int *ac, char **av)
{
	int		x;
	int		updated_ac;
	char	tmp_av[6666][11];
	char	**new_av;

	set_everything_null(tmp_av);
	updated_ac = 0;
	x = 1;
	while (x < *ac)
	{
		if (its_string(av[x]))
			splitter(av[x], tmp_av, &updated_ac);
		else
		{
			if (ft_strlen(av[x]) > INT_MAX_LEN)
			{
				print_error();
				exit(1);
			}
			ft_strlcpy(tmp_av[updated_ac++], av[x], ft_strlen(av[x]) + 1);
		}
		x++;
	}
	*ac = updated_ac + 1;
	new_av = NULL;
	new_av = update_av(updated_ac, tmp_av);
	return (new_av);
}