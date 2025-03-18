NAME = push_swap

NAME_BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = not_your_libft/libft.a

SRC =	Fighters/moves_1.c \
		Fighters/moves_2.c \
		Fighters/push_swap.c \
		Fighters/LIS_array.c \
		Fighters/LIS_length.c \
		Fighters/pre-sorting.c \
		Fighters/deciphering.c \
		Fighters/moves_wannabe.c \
		Fighters/stack_creator.c \
		Fighters/i_got_ur_back.c \
		Fighters/export_operations.c \
		Fighters/calculate_devider.c \
		Fighters/nodes_goingback_home.c \
		Fighters/stack_a_need_some_moves.c \
		Fighters/stack_b_need_some_moves.c \
		Fighters/understanding_deciphering.c 

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Lnot_your_libft -lft 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) -Lnot_your_libft -lft 


$(LIBFT):
	make -s bonus -C not_your_libft 
	make -s -C not_your_libft 

%.o: %.c
	$(CC) $(CFLAGS) -Inot_your_libft -c $< -o $@

clean:
	rm	-f	$(OBJ) $(OBJ_BONUS)
	make -C not_your_libft clean 

fclean: clean
	rm	-f	$(NAME) $(NAME_BONUS)
	make -C not_your_libft fclean

re:	fclean	all	

.PHONY: all clean fclean re