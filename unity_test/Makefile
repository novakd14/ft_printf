CC = cc
# CFLAGS = -Wall -Wextra -Werror -g

NAME = test.exe
NAMEREF = test_ref.exe
TEST = test_ft_printf.c
TEST_REF = test_printf.c
SRCS = unity.c $(TEST)
SRCSREF = unity.c $(TEST_REF)
LIBS = ../ft_printf/libftprintf.a
OBJS = $(SRCS:.c=.o)
OBJSREF = $(SRCSREF:.c=.o)

.PHONY: all clean fclean re test test_ref memleak $(LIBS)

all: $(NAME) $(NAMEREF)

$(NAME): $(OBJS) $(LIBS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

$(NAMEREF): $(OBJSREF) $(LIBS)
	$(CC) -o $(NAMEREF) $(OBJSREF) $(LIBS)

clean:
	rm -f $(OBJS) $(OBJSREF)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBS):
	make -C ../ft_printf

$(TEST): $(TEST_REF)
	rm -f $(TEST:.c=.o)
	cp $(TEST_REF) $(TEST)
	sed -i 's/test_printf/test_ft_printf/g' $(TEST)
	sed -i 's/= printf/= ft_printf/g' $(TEST)

test: $(NAME) $(TEST)
	clear
	./$(NAME)

test_ref: $(NAMEREF)
	clear
	./$(NAMEREF)

memleak: $(NAME)
	valgrind -s --leak-check=full ./$(NAME)
# valgrind --leak-check=full ./$(NAME)
