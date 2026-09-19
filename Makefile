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
	expand_redirs.c \
	exec_error.c \
	exec_path.c \
	exec_external.c \
	execute.c \
	write_string.c \
	builtin_echo.c \
	builtin_pwd.c \
	builtins.c \
	env_edit.c \
	builtin_export.c \
	builtin_unset.c \
	export_sort.c \
	export_print.c \
	env_exec.c \
	env_assign.c \
	builtin_cd.c \
	exit_number.c \
	builtin_exit.c \
	fd_utils.c \
	redirections.c \
	execute_parent.c \
	pipeline.c \
	pipeline_child.c \
	pipeline_wait.c \
	heredoc_file_utils.c \
	heredoc_file.c \
	heredoc_expand.c \
	heredoc_read.c \
	heredoc.c \
	input.c \
	signals.c

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