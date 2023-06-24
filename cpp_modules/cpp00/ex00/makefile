FILE=$(wildcard *.cpp)
CC=clang++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=megaphone

all:
	$(CC) $(FLAGS) $(FILE) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: clean all
