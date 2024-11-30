CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

LFLAGS = -lmlx -lXext -lX11 -lm

LIBFT = libft/libft.a

NAME = fractol

SRC = main.c initializations.c helpers.c put_fract.c color.c\
mouse_events.c keyboard_events.c newton.c color_conv.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS) $(LIBFT)

$(LIBFT):
	@make -C libft --no-print-directory

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C libft clean --no-print-directory

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
