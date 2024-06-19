CC = cc
# CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c ft_set_conversion.c ft_save_char.c ft_save_str.c ft_save_ptr.c \
	ft_save_int.c ft_save_uint.c ft_save_hexa_small.c ft_save_hexa_big.c ft_save_pct.c \
	ft_save_flags.c ft_cpyextra.c ft_put_arg.c
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

