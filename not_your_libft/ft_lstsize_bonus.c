/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:55:03 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/11 21:55:03 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		x;
	t_list	*current;

	x = 1;
	if (!lst)
		return (0);
	current = lst->next;
	while (current != lst)
	{
		current = current->next;
		x++;
	}
	return (x);
}
