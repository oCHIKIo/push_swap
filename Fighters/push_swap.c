/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:12:07 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 00:36:57 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_decreasing_elements(t_list *stack_a)
{
	int		upper_length;
	t_list	*current;

	upper_length = 0;
	current = stack_a;
	while (1)
	{
		upper_length++;
		if (*current->content > *current->next->content)
			break ;
		current = current->next;
	}
	return (upper_length);
}

void	sort_stacks(t_value *data)
{
	int	upper_length;

	if (ft_lstsize(data->stack_a) == 1)
		return ;
	data->nodes_to_push_b_to_a = ft_lstsize(data->stack_b);
	while (data->nodes_to_push_b_to_a)
		going_back_home(data);
	while (data->stack_b)
		operation_push(data, b_to_a);
	upper_length = count_decreasing_elements(data->stack_a);
	while (*data->stack_a->content > *data->stack_a->prev->content)
	{
		if (upper_length < ft_lstsize(data->stack_a) - upper_length)
			operation_rotate_single(&data->stack_a, ra);
		else
			operation_rrotate_single(&data->stack_a, rra);
	}
}

int	main(int ac, char **av)
{
	t_value	*data;
	int		*input_arr;
	int		*lis_tab;

	lis_tab = NULL;
	if (ac == 1)
		return (1);
	av = deciphering(&ac, av);
	if (av == NULL || !av[1])
		return (print_error(), free_everything(NULL, NULL, NULL, av));
	if (!understanding_deciphering(av, ac))
		return (print_error(), free_everything(NULL, NULL, NULL, av));
	if (!string_to_integer(ac, av, &input_arr))
		return (print_error(), free_everything(NULL, input_arr, NULL, av));
	if (!create_stack(&data, input_arr, ac - 1))
		return (print_error(), free_everything(data, input_arr, NULL, av));
	if (stack_a_is_reversed(data->stack_a)
		&& !stack_a_is_ordered(data->stack_a))
		operation_swap_single(data->stack_a, sa);
	if (!lis_arr(data->stack_a, &lis_tab, data))
		return (print_error(), free_everything(data, input_arr, lis_tab, av));
	calculate_devider(data, input_arr);
	pre_sort_stack_a(data, lis_tab);
	sort_stacks(data);
	free_everything(data, input_arr, lis_tab, av);
}
