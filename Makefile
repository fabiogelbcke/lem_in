CC = gcc

FLAGS = #-Wall -Wextra -Werror -g

SRC =	lem_in.c \
	helper_functions.c \
	utils.c \

OBJ	= $(SRC:.c=.o)

LIB 	= libft/libft.a

NAME = lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
