NAME = libftprintf.a

SRC = ft_atoi.c \
	ft_flags_to_zero.c \
	ft_get_flags.c \
	ft_print_regular_symb.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_work_with_type.c

OBJ = $(SRC:.c=.o)

HDR = ft_printf.h libftprintf.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ) $(HDR)
	ar rc $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) $?

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all