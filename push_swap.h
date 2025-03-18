/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiki <bchiki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:27:54 by bchiki            #+#    #+#             */
/*   Updated: 2025/03/18 14:09:40 by bchiki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "not_your_libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* ░█▀▀░▀█▀░█▀▄░█░█░█▀▀░▀█▀░█▀▀░█▀▄░█▀▀ */
/* ░▀▀█░░█░░█▀▄░█░█░█░░░░█░░█▀▀░█▀▄░▀▀█ */
/* ░▀▀▀░░▀░░▀░▀░▀▀▀░▀▀▀░░▀░░▀▀▀░▀░▀░▀▀▀ */

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

/* ░█▀▀░█░█░█▀█░█▀█░█▀▄░▀█▀ */
/* ░█▀▀░▄▀▄░█▀▀░█░█░█▀▄░░█░ */
/* ░▀▀▀░▀░▀░▀░░░▀▀▀░▀░▀░░▀░ */

int			fake_abs(int value);
int			min_value(int value_1, int value_2);
void		operations_functions(t_value *data, int i_tab[]);
void		export_operations(t_value *data, int moves_needed[]);

/* ░█▀▄░█▀▀░█░█░▀█▀░█▀▄░█▀▀░█▀▄ */
/* ░█░█░█▀▀░▀▄▀░░█░░█░█░█▀▀░█▀▄ */
/* ░▀▀░░▀▀▀░░▀░░▀▀▀░▀▀░░▀▀▀░▀░▀ */

void		swap(int *a, int *b);
void		sort_just_for_devider(int size, int tmp_tab[]);
void		calculate_devider(t_value *data, int *input_tab);
void		devider_value(t_value *data, int tmp_tab[], int size);

/* ░█▀▄░█▀▀░█▀▀░▀█▀░█▀█░█░█░█▀▀░█▀▄░▀█▀░█▀█░█▀▀░░░░ */
/* ░█░█░█▀▀░█░░░░█░░█▀▀░█▀█░█▀▀░█▀▄░░█░░█░█░█░█░░░░ */
/* ░▀▀░░▀▀▀░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░░░░ */

bool		its_string(char *str);
char		**deciphering(int *ac, char **av);
void		set_everything_null(char tmp_av[][11]);
char		**update_av(int updated_ac, char tmp_av[][11]);
void		splitter(char *str, char tmp_av[][11], int *updated_ac);

/* ░█▄█░█▀█░█░█░█▀▀░█▀▀░░░▀█░ */
/* ░█░█░█░█░▀▄▀░█▀▀░▀▀█░░░░█░ */
/* ░▀░▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░▀▀▀ */

void		operation_swap_double(t_value *data);
void		operation_print(enum t_operation instruction);
void		operation_push(t_value *data, enum t_direction direction);
void		operation_swap_single(t_list *stack, enum t_operation operation);

/* ░█▄█░█▀█░█░█░█▀▀░█▀▀░░░▀▀▄ */
/* ░█░█░█░█░▀▄▀░█▀▀░▀▀█░░░▄▀░ */
/* ░▀░▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░▀▀▀ */

void		operation_rotate_double(t_value *data);
void		operation_rrotate_single(t_list **stack,
				enum t_operation operation);
void		operation_rrotate_double(t_value *data);
void		operation_rotate_single(t_list **stack, enum t_operation operation);

/* ░▀█▀░░░█▀▀░█▀█░▀█▀░░░█░█░█▀▄░░░█▀▄░█▀█░█▀▀░█░█ */
/* ░░█░░░░█░█░█░█░░█░░░░█░█░█▀▄░░░█▀▄░█▀█░█░░░█▀▄ */
/* ░▀▀▀░░░▀▀▀░▀▀▀░░▀░░░░▀▀▀░▀░▀░░░▀▀░░▀░▀░▀▀▀░▀░▀ */

void		del(void *nil);
int			print_error(void);
int			free_everything(t_value *data, int *input_arr, int *lis_arr,
				char **av);

/* ░█░░░▀█▀░█▀▀░░░░░█▀█░█▀▄░█▀▄ */
/* ░█░░░░█░░▀▀█░░░░░█▀█░█▀▄░█▀▄ */
/* ░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀░▀░▀░▀ */

void		shortcut(int **lis_arr);
int			lis_hunter(int dp_tab[][6666], int lis);
void		initialize_tabs_both(t_list *node, int tab[][6666]);
int			lis_arr(t_list *stack_a, int **lis_arr, t_value *data);
void		lis_filler(int *lis_tab, int tab[][6666], int lis, int size);

/* ░█░░░▀█▀░█▀▀░▀█▀░░░░░█░░░█▀▀░█▀█░█▀▀░▀█▀░█░█ */
/* ░█░░░░█░░▀▀█░░█░░░░░░█░░░█▀▀░█░█░█░█░░█░░█▀█ */
/* ░▀▀▀░▀▀▀░▀▀▀░░▀░░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░░▀░▀ */

int			lis_length(t_list *stack);
int			lis_length_hunter(t_list *node);
void		fill_second_array(long int tabs[][6666], int node_size);
void		initialize_tabs(long int tab[][6666], t_list *node, int size);
void		hunt_for_lis_in_second_array(long int arr_2[], int *lis,
				int node_size);

/* ░█▄█░█▀█░█░█░█▀▀░░░█░█░█▀█░█▀█░█▀█░█▀█░█▀▄░█▀▀ */
/* ░█░█░█░█░▀▄▀░█▀▀░░░█▄█░█▀█░█░█░█░█░█▀█░█▀▄░█▀▀ */
/* ░▀░▀░▀▀▀░░▀░░▀▀▀░░░▀░▀░▀░▀░▀░▀░▀░▀░▀░▀░▀▀░░▀▀▀ */

void		remove_top_node(t_list **pile);
void		swap_node_data(t_list *node1, t_list *node2);
void		send_top_node(t_value *data, enum t_direction direction);

/* ░█▀█░█▀█░█▀▄░█▀▀░█▀▀░░░░░█▀▀░█▀█░▀█▀░█▀█░█▀▀░█▀▄░█▀█░█▀▀░█░█░░░░ */
/* ░█░█░█░█░█░█░█▀▀░▀▀█░░░░░█░█░█░█░░█░░█░█░█░█░█▀▄░█▀█░█░░░█▀▄░░░░ */
/* ░▀░▀░▀▀▀░▀▀░░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀░░▀░▀░▀▀▀░▀░▀░▀▀▀ */
/* ░█░█░█▀█░█▄█░█▀▀                                                 */
/* ░█▀█░█░█░█░█░█▀▀                                                 */
/* ░▀░▀░▀▀▀░▀░▀░▀▀▀                                                 */

void		going_back_home(t_value *data);
void		initialize_variables(int moves_needed[], int tmp_moves_needed[],
				int *lowest_move_cost);
void		update_variables(int *lowest_move_cost, int *tmp_lowest_move_cost,
				int moves_needed[], int tmp_moves_needed[]);

/* ░█▀█░█▀▄░█▀▀░░░░░█▀▀░█▀█░█▀▄░▀█▀░▀█▀░█▀█░█▀▀ */
/* ░█▀▀░█▀▄░█▀▀░░░░░▀▀█░█░█░█▀▄░░█░░░█░░█░█░█░█ */
/* ░▀░░░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀░▀▀▀ */

int			stack_a_is_ordered(t_list *stack);
int			stack_a_is_reversed(t_list *stack);
int			is_in_lis_arr(t_list *node, int *lis_tab);
void		pre_sort_over_50(t_value *data, int *lis_arr);
void		pre_sort_stack_a(t_value *data, int *lis_arr);

/* ░█▀█░█░█░█▀▀░█░█░░░█▀▀░█░█░█▀█░█▀█ */
/* ░█▀▀░█░█░▀▀█░█▀█░░░▀▀█░█▄█░█▀█░█▀▀ */
/* ░▀░░░▀▀▀░▀▀▀░▀░▀░░░▀▀▀░▀░▀░▀░▀░▀░░ */

int			main(int ac, char **av);
void		sort_stacks(t_value *data);
int			count_decreasing_elements(t_list *stack_a);

/* ░█░█░█▀█░█▀▄░█▀▀░█▀▄░█▀▀░▀█▀░█▀█░█▀█░█▀▄░▀█▀░█▀█░█▀▀ */
/* ░█░█░█░█░█░█░█▀▀░█▀▄░▀▀█░░█░░█▀█░█░█░█░█░░█░░█░█░█░█ */
/* ░▀▀▀░▀░▀░▀▀░░▀▀▀░▀░▀░▀▀▀░░▀░░▀░▀░▀░▀░▀▀░░▀▀▀░▀░▀░▀▀▀ */
/* ░█▀▄░█▀▀░█▀▀░▀█▀░█▀█░█░█░█▀▀░█▀▄░▀█▀░█▀█░█▀▀░░░░     */
/* ░█░█░█▀▀░█░░░░█░░█▀▀░█▀█░█▀▀░█▀▄░░█░░█░█░█░█░░░░     */
/* ░▀▀░░▀▀▀░▀▀▀░▀▀▀░▀░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░░░░     */

int			there_is_sign(char x);
int			is_well_formed_number(char *num);
int			is_beyond_int_limits(const char *str);
int			understanding_deciphering(char **av, int ac);

/* ░█▀▀░▀█▀░█▀█░█▀▀░█░█░░░░░█▀█░░░░░█▀█░█▀▀░█▀▀░█▀▄░░░░ */
/* ░▀▀█░░█░░█▀█░█░░░█▀▄░░░░░█▀█░░░░░█░█░█▀▀░█▀▀░█░█░░░░ */
/* ░▀▀▀░░▀░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀░░▀▀▀ */
/* ░█▀▀░█▀█░█▄█░█▀▀░░░░░█▄█░█▀█░█░█░█▀▀░█▀▀             */
/* ░▀▀█░█░█░█░█░█▀▀░░░░░█░█░█░█░▀▄▀░█▀▀░▀▀█             */
/* ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░░▀▀▀░▀▀▀             */

int			should_break_here(t_list *current, int node_value);
void		moves_we_need_for_stack_a(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_forward_moves_stack_a(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_backward_moves_stack_a(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		just_one_node_to_check_in_stack_b(t_value *data,
				int tmp_moves_needed[], int *tmp_max_possible);

/* ░█▀▀░▀█▀░█▀█░█▀▀░█░█░░░░░█▀▄░░░░░█▀█░█▀▀░█▀▀░█▀▄░░░░ */
/* ░▀▀█░░█░░█▀█░█░░░█▀▄░░░░░█▀▄░░░░░█░█░█▀▀░█▀▀░█░█░░░░ */
/* ░▀▀▀░░▀░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀░░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀░░▀▀▀ */
/* ░█▀▀░█▀█░█▄█░█▀▀░░░░░█▄█░█▀█░█░█░█▀▀░█▀▀             */
/* ░▀▀█░█░█░█░█░█▀▀░░░░░█░█░█░█░▀▄▀░█▀▀░▀▀█             */
/* ░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░░▀░░▀▀▀░▀▀▀             */

void		moves_we_need_for_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_forward_moves_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);
void		find_optimal_backward_moves_stack_b(t_value *data, t_list *node,
				int tmp_moves_needed[], int *tmp_lowest_move_cost);

/* ░█▀▀░▀█▀░█▀█░█▀▀░█░█░░░░░█▀▀░█▀▄░█▀▀░█▀█░▀█▀░█▀█░█▀▄ */
/* ░▀▀█░░█░░█▀█░█░░░█▀▄░░░░░█░░░█▀▄░█▀▀░█▀█░░█░░█░█░█▀▄ */
/* ░▀▀▀░░▀░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀░▀░░▀░░▀▀▀░▀░▀ */

int			string_to_integer(int ac, char **av, int **input_arr);
int			create_stack(t_value **data, int *input_arr, int arr_size);

#endif
••••••••••••••••••«««««••««««««••«««••••••«««««««««««««««««««««••••••••••••••••
•••••••••••••••••••••••«««••«•••««««««••••••••••••••••••««««««««««««««««««««««•
••••••••••••••••••••••••••««««•«««•««•«««••••••••••••••••••••••••••••••••••««««
•••••••••••••••••••••••••«•••«««««««««««««««•••••••••••••••••••••••••••••••••••
••••••••••••••••••••••••••••••••«««••«««««•••««««••••••••••••••••••••••••••••••
••••••••••••••••••••••••••••••••••«•«««•«««•«««««••••••••••••••••••••••••••••••
••••••••••••••••••••••••••••••••••••••««««••««•«•«««•••••••••••••••••••••••••••
•••••••••••••••••••••••••••••••••••••••••««««•««•««••««••••••••••••••••••••••••
••••••••••••••••••••••••••••••••••••••••••••••««••«•««•««••••••••••••••••••••••
•••••••••••••••••••••••••••••••••••••••••••••••••««••«•««•««•••••••••••••••••••
••••••••••••••••••••••••••••••••••««••••••••••••••••««••«•«••««««««••••••••••••
••••••••••••••••••••••••••««•«IÔÕÕÕÕÕÕÕÕÕÔ5••••••••••••««•««•«••«««••••••••••••
••••••••••••••••••••••••••ßÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕú•••••••••••••««••«««•««««•••••••••
••••••••••••••••••••••••«ÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕÕ«••••••••••••«•««••««••««••••••••
•••••••••••••••••••••••«ÔÕÕÕÕÕÕÕÕÕãéÙà5ò1ïítsZÕŸ•••••••••••••••••«•«•«••«••••••
••••••••••••••••••••••«ÕÕÕâk±ó0©Vö¼¤íí<i†<ï<íï3Õ0•••••••••••••••••••«••••••••••
•••••••••••••••••••••«ÕÕžJIrc¤‰u‡zƒƒIíï<<ííîIlíhÔ«•••••••••••••••••••••••••••••
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬»ÕÕ2I¤cïïï[7vïî<+??{†ï<<<í&Õ}¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬••••••
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬«ÕÕµ¼ír%†?†??c¤urJvîö@ööuƒ‰ø4•¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬•¬
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬•ÔÕÝó@‰ususó@l>ïcVÌÌ©žÞÚÜåžOÕ•¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬•ÔßeämA€ÔÔmâÙf¤¤ÌDAÕÕÕÕÔã8äwët¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬«f
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ëøx§øAÕÕÕÕÕÔé>»}@$€ßðßÕ€ã¶ñ¾ß¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬»ýÕÕ
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬ÇëaÚøÚ¶ÜZëÙD©<««»JxšPxõOxç£3®¿¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬[¶ÕÕÕÕÕ
¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬3ßÒçüôúú2çüçÌ@(«••)@±ö22VC½@V©ö¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬•öÕÕÕÕÕÕÕÕÕ
¬¬¬¬¬¬¬¬¬¬•¬¬¬¬¬¬¬¬¬(öTõ0Ì‰só±ó‡‰±ÌJ†}[¼£©ÌJ‰s3©©ç£I¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬iôÔÕÕÕÕÕÕÔÔA
¬¬¬¬¬¬¬••¬+r¬¬¬¬¬¬¬¬µô££0©3C‰%I%Ì±äGÇ¾¾àø$SOÌn2ü£VÌ+¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬Amãããââß
¬¬¬/ír®ßßD3••¬¬¬¬¬¬¬µFç£0±Ì3C‰‡Ì0ú$â¶ø¶âãbÍ0ú©©£V3¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬kããßmmßß
®Fäy6ÇFZàäÚýS+¬¬¬¬¬»$¶®3ÌÌsÌ0Ì3±nCažÓ¶øëñ62V±V©00C¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬9ßßpmmmp
A€A€€pmmmãG¶¶¶éëdÞÒFšàDßÕaó@±±CC±©49áŸ9¥äUk®õ£VV0v¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬žÕßmãããââ
døâãããpããßß€AÔÔÕÕÕÔÕÔÔÔÔÔðÏòó30£üeÓëÚð¶p€m$ûž¾©0V¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¿¾Ÿ9GâdÓÓÙýýè
ÕÕÕÕÕÕßßÕÕÕÕÕÕÕAÔÕÕÕÕÕÕÕÕÕeó3©©2õe6x&ffõ¾OT6µŸTôVw½un%}»¤åðßApãã$åbÖ$ýø¶ãmmmßmm
ÕÕÕÕÕÕÔÕÕÕÕ(¬¬«$ÕÕÕÕÕÕÕAÕÜãnÌ0çü5®6ŸåÙ$ÚÜ$$ÇkS9ù3í«•••»}aÕÕÕÕÕÔA€€€AÔA€AÕAmâ¶Gâ
ÕÕÕÕÕÕÕÕÕÕÕ•¬¬«ÜÕÕÕÕÕÕÕÕÕÕÕTÌÌ0™fà$é¶øééÚëDÇûSú±öv«•••••[Ô€¶ââmGøGmßßpmmAß¶éÚÚ8
ÕÕÕÕÕÕÕÕÕÕß¬¬¬<AÕÕÕÕÕÕÕÕÔGÕäVVV02O®ûû9TeOÎeTµü0±<•••»+¿*¼ÔApøGÜGGøßÕÕÕÕÕÕÕÕÕãð¶
ÕâßÙåFPAÕÕÕ€mmÔÕÕÕÕÕÕÕÕÕÕÕÔólV£©£úO6T®kkÝ§žô0Ì£±»•@=v1{}ôÔÔpðdÙëëëèýémÔÕÕÕÕÕÕÕ€
Ô21î4e&O8ÕÕÕÕÕÕÕÕÕÔÔÔÔÔÕÕøÔ»«@Ì3300çô¾e99ô3@ó‰/•••V¶¶Y)»smøÓýÞ¥Zàá¥bÕÕÕppßÕ€ãGÞ
ÕÕÕÔ€p¶ýÞbåÞÿåÒÒÓdðâøââmmüø«¬••)Jòöö@Ìs‡l•••¬¬¬¬¬•õ¶¶ã¶ðéÔãPàÝ0žûšäé¶ÕÕÞÙëð$ÓÖ¥
àekáFäÝ®9TTOeµUUT®Ÿ§ûÝhäéâô¬¬¬¬¬¬¬¬•<Ç(•¬¬¬¬¬¬•••%ýøâßâââGøðéÖ•¾PÇÇáÞÕÕFÿð¶$ddÓ
wôçaô2±Ì‰@ò¢ösòöòÌóVÌaD¶mÚ•¬¬¬¬¬¬•vZZZZç«•¬¬¬¬¬•+bøøøâãøø¶âââå@I%J@úkÜâåãGøðééÖ
•••••••••••••••••••«OøâãGU•¬¬¬••6ZZZZZZZZ¾•¬¬¬¬«ûøøøðGpøÙë8¶ââ¶âéb¾î}({×<I¼‰òÏw
•••••••••••••«•«}&8ééâmGøû•¬¬¬•ZZZZZZZZZZÝ•¬¬¬•YÚ8øø¶¶mGëëÚøøø¶âG¶¶¶¶¶¶øýkÍzîjl
•••••••••••••»wÚøøÚ¶ãâ¶Üëá•¬••«ZZZZZZZZZL•••¬•)ý$$ø¶øøãâ8Üøøøøøøø¶GâG¶ââG¶¶¶¶¶ø
•••••••••••×ñéð$ëÚâãGé$8Úû••••JZZZZZZZZZ»¬¬••«®Ú$Üé¶ø¶âm¶Úéøøøøøøøø¶¶¶GâââÚeTxF
•••••••••«ZøðÚÚé¶âG¶¶Üd$øÚu•¬•ÝZZZZZZZZŸ•¬¬¬•ÖéÚÚÚ¶¶¶ââããéë$$dýëëÜÜøGøøGââOï[«u
•••••••••38ø8Ü8¶ãG¶ø¶¶G¶¶Ü¿¬¬»ZZZZZZZZZa•¬¬•£ðøøøøø¶¶¶¶âãø$ddddddýýëÜø¶¶¶GøåÖaà
«««»»/)(=øGG¶â¶¶GâßAAßmGø¶¿¬•¢ZZZZZZZZZ‰•¬•«ø¶âmmßpmmpßmmâøøééééééééééø¶âââGGââ
