/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:53:34 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/11 21:53:34 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		(*lst)->prev->next = new;
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
	}
}