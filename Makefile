NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
PARSING_DIR = $(SRC_DIR)/parsing
MVM_DIR = $(SRC_DIR)/movement
TEXTURES_DIR = $(SRC_DIR)/textures
MLX_DIR = $(SRC_DIR)/mlx
UTILS_DIR = $(SRC_DIR)/utils
HEADER_DIR = $(SRC_DIR)/headers

GNL_DIR = includes/getnextline
PRINTF_DIR = includes/ft_printf
LIBFT_DIR = $(PRINTF_DIR)/libft
MiniLX_DIR = includes/minilibx-linux

SRCS = \
	$(SRC_DIR)/so_long.c \
	$(UTILS_DIR)/free.c \
	$(PARSING_DIR)/parsing.c \
	$(PARSING_DIR)/utils.c \
	$(PARSING_DIR)/validate_map.c \
	$(GNL_DIR)/get_next_line.c \
	$(GNL_DIR)/get_next_line_utils.c \
	$(MLX_DIR)/mlx_init.c \
	$(MLX_DIR)/hooks.c \
	$(TEXTURES_DIR)/textures.c \
	$(MVM_DIR)/movement.c

OBJS = $(SRCS:.c=.o)

PRINTF = $(PRINTF_DIR)/libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MiniLX_DIR)/libmlx.a

INCLUDES = \
	-I$(HEADER_DIR) \
	-I$(GNL_DIR) \
	-I$(PRINTF_DIR) \
	-I$(LIBFT_DIR) \
	-I$(MiniLX_DIR)

MLX_FLAGS = -L$(MiniLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(PRINTF_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MiniLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) \
	$(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MiniLX_DIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re