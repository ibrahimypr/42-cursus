

NAME = a.out
CC = clang++ -std=c++98
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./
SRC	= 	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp

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
