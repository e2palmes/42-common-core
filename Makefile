NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lreadline

SRC = main.c \
	env.c \
	builtin_env.c \
	token.c \
	lexer_utils.c \
	lexer.c \
	syntax.c \
	command.c \
	parser.c \
	parser_debug.c \
	env_value.c \
	expand_variable.c \
	expand_buffer.c \
	expand_scan.c \
	expand_word.c \
	expand_words.c \
	prepare_commands.c \
	expand_redirs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDLIBS) -o $(NAME)

%.o: %.c minishell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re