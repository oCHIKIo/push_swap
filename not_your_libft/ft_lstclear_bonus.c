/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:53:56 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/11 21:53:56 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	if (!current)
		return ;
	while (1)
	{
		next = current->next;
		ft_lstdelone(current);
		current = next;
		if (current == *lst)
			break ;
	}
	*lst = NULL;
}
