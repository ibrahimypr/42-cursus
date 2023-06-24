NAME	=	phonebook

CC		=	c++
W_FLAGS	=	-Wall -Wextra -Werror
S_FLAGS =	-std=c++98
RM		=	rm -rf
OBJ 	=	$(patsubst %.cpp, %.o, $(SRC))

.PHONY:		all clean fclean re test


RED= \033[4;31m
GREEN= \033[0;32m
NC= \033[0;0m

INC		=	contact.hpp phonebook.hpp
SRC		=	main.cpp contact.cpp phonebook.cpp

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(W_FLAGS) $(S_FLAGS) $(OBJ) -o $(NAME)
			@echo -e "$(GREEN)\t\n Phonebook compiled!\n $(NC)"

%.o : %.cpp	Makefile $(INC)
			$(CC) $(W_FLAGS) $(S_FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)
			@echo "$(RED)*.o files is clean!$(NC)"

fclean:		clean
			$(RM) $(NAME)
			@echo "$(RED)All files is clean!$(NC)"

re:			fclean all

test:		$(NAME)