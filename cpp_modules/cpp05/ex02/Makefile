NAME = bureaucrat

FILES = $(wildcard *.cpp)

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJECTS = $(FILES:.cpp=.o)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all