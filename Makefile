NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes
LDLIBS = -lreadline

SRC_DIRS = src \
		src/builtins \
		src/env \
		src/lexer \
		src/parser \
		src/expansion \
		src/execution \
		src/heredoc \
		src/signals \
		src/input \
		src/utils

SRCS = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))

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