CC = cc
# CFLAGS = -Wall -Wextra -Werror -g

NAME = test.exe
SRCS = main_test.c test_cases_fnc.c test_print2file.c
LIBS = ../libftprintf.a ../libft/libft.a
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re lib test memleak

all: $(NAME)

$(NAME): $(OBJS) lib
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make -C ../

test: $(NAME)
	clear
	./$(NAME)

memleak: $(NAME)
	valgrind -s --leak-check=full ./$(NAME)
# valgrind --leak-check=full ./$(NAME)
