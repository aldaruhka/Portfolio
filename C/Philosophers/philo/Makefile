NAME = philo
SRC = philo.c \
	philo_info_init.c \
	philosophers_init.c \
	main_thread.c \
	philo_threads.c \
	philo_actions.c \
	utils.c
OBJ = ${SRC:.c=.o}
HDR = philo.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -pthread $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HDR)
	$(CC) -pthread $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
