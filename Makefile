CC = gcc

FLAGS = #-Wall -Wextra -Werror -g

SRC =	lem_in.c \
	helper_functions.c

OBJ	= $(SRC:.c=.o)

LIB 	= libft/libft.a

NAME = lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ./libft
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB)

test:
	git clone https://github.com/yyang42/moulitest.git

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
