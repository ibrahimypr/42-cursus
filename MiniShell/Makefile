NAME = minishell
CC = gcc
FLAGS = -Wall -Werror -Wextra  -g -I /goinfre/homebrew/opt/readline/include
RM = rm -rf
SOURCE = $(wildcard src/*.c libft/*.c)
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib
OBJECTS = $(SOURCE:.c=.o)
.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)
$(NAME): $(OBJECTS) minishell.h
	$(CC) $(FLAGS) $(READLINE) $(OBJECTS) -o $(NAME)
clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re