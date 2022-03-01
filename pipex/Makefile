NAME = pipex

SRC = pipex.c \
	open_file.c \
	take_path.c \
	utils.c \
	work_with_path_and_argv.c

OBJ = $(SRC:.c=.o)

GNL = get_next_line.c \
	get_next_line_utils.c

GNL_OBJ = $(GNL:.c=.o)

HDR = pipex.h

GNL_HDR = get_next_line.h

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: liba main

liba:
	$(MAKE) -C $(LIBFT_PATH)

main: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(GNL_OBJ) $(LIBFT) -o $(NAME)

%.o : %.c $(HDR) $(GNL_HDR)
	$(CC) $(CFLAGS) -c $<

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all liba main clean fclean re
