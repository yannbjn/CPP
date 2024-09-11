SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

NAME = brain

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re