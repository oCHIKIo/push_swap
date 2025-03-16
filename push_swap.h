/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:27:54 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/13 03:17:10 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "not_your_libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_value
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nodes_to_push_b_to_a;
	int		lis_length;
	int		devider_arr[1];
}			t_value;

typedef enum t_direction
{
	a_to_b,
	b_to_a
}			t_direction;

typedef enum t_operation
{
	nothing_here,
	rr,
	rrr,
	ra,
	rb,
	rra,
	rrb,
	sa,
	sb,
	ss,
	pa,
	pb
}			t_operation;

/* export operations */
int			fake_abs(int value);
int			min_value(int value_1, int value_2);
void		operations_functions(t_value *data, int i_tab[]);
void		export_operations(t_value *data, int moves_needed[]);

/* DEVIDER*/
void		swap(int *a, int *b);
void		sort_just_for_devider(int size, int tmp_tab[]);
void		calculate_devider(t_value *data, int *input_tab);
void		devider_value(t_value *data, int tmp_tab[], int size);

/* deciphering */
bool		its_string(char *str); /* hadi kant int rditha bool */
char		**deciphering(int *ac, char **av);
void		set_everything_null(char tmp_av[][11]);
char		**update_av(int updated_ac, char tmp_av[][11]);
void		splitter(char *str, char tmp_av[][11], int *updated_ac);

/* export operations   -- moves_2 */
void		operation_rotate_double(t_value *data);
void		operation_rrotate_single(t_list **stack,
	enum t_operation operation);
void		operation_rrotate_double(t_value *data);
void		operation_rotate_single(t_list **stack, enum t_operation operation);

/* moves_1 */
void		operation_swap_double(t_value *data);
void		operation_print(enum t_operation instruction);
void		operation_push(t_value *data, enum t_direction direction);
void		operation_swap_single(t_list *stack, enum t_operation operation);

/* i got ur back */
void		del(void *nil);
int			print_error(void);
int			free_everything(t_value *data, int *input_arr, int *lis_arr,
				char **av);

/* lis_arr*/
void		shortcut(int **lis_arr);
int			LIS_hunter(int dp_tab[][6666], int lis);
void		initialize_tabs_both(t_list *node, int tab[][6666]);
int			LIS_arr(t_list *stack_a, int **lis_arr, t_value *data);
void		LIS_filler(int *lis_tab, int tab[][6666], int lis, int size);


/* list_length */
int			LIS_length(t_list *stack);
int			LIS_length_hunter(t_list *node);
void		fill_second_array(long int tabs[][6666], int node_size);
void		initialize_tabs(long int tab[][6666], t_list *node, int size);
void		hunt_for_LIS_in_second_array(long int arr_2[], int *lis, int node_size);


/* move wannabe */
void		remove_top_node(t_list **pile);
void		swap_node_data(t_list *node1, t_list *node2);
void		send_top_node(t_value *data, enum t_direction direction);

/* node_goingback_home.c */
void		going_back_home(t_value *data);
void		initialize_variables(int moves_needed[], int tmp_moves_needed[],
				int *lowest_move_cost);
void		update_variables(int *lowest_move_cost, int *tmp_lowest_move_cost,
				int moves_needed[], int tmp_moves_needed[]);

/* pre_sorting*/
int			stack_a_is_ordered(t_list *stack);
int			stack_a_is_reversed(t_list *stack);
int			is_in_LIS_arr(t_list *node, int *lis_tab);
void		pre_sort_over_50(t_value *data, int *lis_arr);
void		pre_sort_stack_a(t_value *data, int *lis_arr);

/* push swap.c */
int			main(int ac, char **av);
void		sort_stacks(t_value *data);
int			count_decreasing_elements(t_list *stack_a);

/* understanding deciphering */
int			there_is_sign(char x);
int			is_well_formed_number(char *num);
int			is_beyond_int_limits(const char *str);
int			understanding_deciphering(char **av, int ac);

/* stack_a_need_some_moves */
int			should_break_here(t_list *current, int node_value);
void		moves_we_need_for_stack_a(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_forward_moves_stack_a(t_value *data, t_list *node,
		int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_backward_moves_stack_a(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void	just_one_node_to_check_in_stack_b(t_value *data, int tmp_moves_needed[],
					int *tmp_max_possible);
		
/* stack_b_need_some_moves */
void		moves_we_need_for_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_forward_moves_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_backward_moves_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);

/* stack_creator */
int	string_to_integer(int ac, char **av, int **input_arr);
int	create_stack(t_value **data, int *input_arr, int arr_size);


#endif