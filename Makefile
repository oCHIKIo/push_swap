NAME = push_swap

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

REBUILDING = 0

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Lnot_your_libft -lft 
	@if [ $(REBUILDING) -eq 0 ]; then \
		printf "\033[1;32m🐺 Push_swap Built Successfully! 🐺\033[0m\n"; \
	fi

$(LIBFT):
	@make -s -C not_your_libft 

%.o: %.c
	@$(CC) $(CFLAGS) -Inot_your_libft -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -s -C not_your_libft clean 
	@if [ $(REBUILDING) -eq 0 ] && [ "$(MAKECMDGOALS)" = "clean" ]; then \
		printf "\033[1;31m🐺 Cleaned Successfully! 🐺\033[0m\n"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@make -s -C not_your_libft fclean
	@if [ $(REBUILDING) -eq 0 ] && [ "$(MAKECMDGOALS)" = "fclean" ]; then \
		printf "\033[1;33m🐺 Force Cleaned Successfully! 🐺\033[0m\n"; \
	fi

re: 
	@$(MAKE) --no-print-directory fclean REBUILDING=1
	@$(MAKE) --no-print-directory all REBUILDING=1
	@printf "\033[1;34m🐺 Rebuilt Successfully! 🐺\033[0m\n"

.PHONY: all clean fclean re