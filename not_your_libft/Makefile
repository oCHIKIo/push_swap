NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =		ft_atoi.c \
			ft_split.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_isdigit.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_memset.c \
			ft_calloc.c \

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:_bonus.c=_bonus.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs	$(NAME)	$(OBJ)

bonus: $(OBJ_BONUS)
	@ar rcs	$(NAME) $(OBJ_BONUS)

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@

clean:
	@rm	-f	$(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm	-f	$(NAME) 

re:	fclean	all