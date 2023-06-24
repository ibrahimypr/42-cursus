NAME = files
SRCS = *.cpp
CMP = c++
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):
	$(CMP) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean : clean

re: fclean all