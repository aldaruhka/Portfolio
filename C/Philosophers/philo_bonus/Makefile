NAME_BON = philo_bonus
SRC_BON = philo_bonus.c \
	philo_info_init_bonus.c \
	philo_init_bonus.c \
	philo_actions_bonus.c \
	utils_bonus.c \
	new_process_actions_bonus.c
OBJ_BON = ${SRC_BON:.c=.o}
HDR_BON = philo_bonus.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME_BON)

$(NAME_BON): $(OBJ_BON)
	$(CC) $(CFLAGS) $(OBJ_BON) -o $(NAME_BON)

%.o: %.c $(HDR_BON)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ_BON)

fclean: clean
	rm -f $(NAME_BON)

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
