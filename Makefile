CFILES = ft_printf.c \
	ft_format_arg.c \
	ft_printchar.c \
	ft_printstr.c \
	ft_printupperhex.c \
	ft_printlowerhex.c \
	ft_printpointer.c \
	ft_printdecimal.c \
	ft_printunsigneddecimal.c
OFILES = $(CFILES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = libft.a

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean:
	rm -f $(NAME) $(OFILES)

$(NAME): $(OFILES)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all
