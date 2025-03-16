/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:53:44 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/11 21:53:44 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
	{
		(*lst)->prev->next = new;
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*lst = new;
}
