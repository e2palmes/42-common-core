NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes
LDLIBS = -lreadline

SRCS = src/builtins/builtin_cd.c \
	src/builtins/builtin_echo.c \
	src/builtins/builtin_env.c \
	src/builtins/builtin_exit.c \
	src/builtins/builtin_export.c \
	src/builtins/builtin_pwd.c \
	src/builtins/builtin_unset.c \
	src/builtins/builtins.c \
	src/builtins/exit_number.c \
	src/builtins/export_print.c \
	src/builtins/export_sort.c \
	src/debug/parser_debug.c \
	src/env/env.c \
	src/env/env_assign.c \
	src/env/env_edit.c \
	src/env/env_exec.c \
	src/env/env_value.c \
	src/execution/exec_error.c \
	src/execution/exec_external.c \
	src/execution/exec_path.c \
	src/execution/execute.c \
	src/execution/execute_parent.c \
	src/execution/fd_utils.c \
	src/execution/pipeline.c \
	src/execution/pipeline_child.c \
	src/execution/pipeline_wait.c \
	src/execution/redirections.c \
	src/expansion/expand_buffer.c \
	src/expansion/expand_redirs.c \
	src/expansion/expand_scan.c \
	src/expansion/expand_variable.c \
	src/expansion/expand_word.c \
	src/expansion/expand_words.c \
	src/expansion/prepare_commands.c \
	src/heredoc/heredoc.c \
	src/heredoc/heredoc_expand.c \
	src/heredoc/heredoc_file.c \
	src/heredoc/heredoc_file_utils.c \
	src/heredoc/heredoc_read.c \
	src/input/input.c \
	src/lexer/lexer.c \
	src/lexer/lexer_utils.c \
	src/lexer/token.c \
	src/main.c \
	src/parser/command.c \
	src/parser/parser.c \
	src/parser/syntax.c \
	src/signals/signals.c \
	src/utils/write_string.c

OBJ_DIR = obj
OBJS = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.c includes/minishell.h
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re