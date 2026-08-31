NAME		= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Sources
SRC			= 	philo.c \
				init.c \
				utils.c \
				forks.c \
				routine.c \
				monitor.c \
				simulation.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re