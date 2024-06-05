CC = cc
# CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c
# BONS =
HEAD = libftprintf.h
LIB = libft/libft.a
OBJS = $(SRCS:.c=.o)
O_BONS = $(BONS:.c=.o)

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS) $(HEAD) $(LIB)
	ar -crs $(NAME) $(OBJS) $(LIB)

$(LIB):
	make -C libft

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(O_BONS)
	ar -crs $(NAME) $(OBJS) $(O_BONS)

norm: all fclean
	norminette $(SRCS) $(BONS) $(HEAD) libft

