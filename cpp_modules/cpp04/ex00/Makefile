
NAME = a.out
CC = c++ -std=c++98
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./
SRC	= $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o	: %.cpp
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean: 
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
