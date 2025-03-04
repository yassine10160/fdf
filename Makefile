CC = cc
CFLAGS = -Wextra -Werror -Wall -g
MLXFLAGS = -lX11 -lXext -lm -lGL -lz
LIBFT_A = src/libft/libft.a
MLX = minilibx-linux/libmlx.a
SRCS =	src/parsing.c src/utils.c src/bresenham.c src/main.c
OBJS =	$(SRCS:.c=.o)
NAME =	fdf

all: $(NAME)

$(NAME): $(OBJS) Makefile $(LIBFT_A) $(MLX)
	cc $(OBJS) -o $(NAME) $(LIBFT_A) $(MLX) $(MLXFLAGS)

%.o: %.c libft.h mlx.h
	$(CC) $(CFLAGS) -c $< -o $@ $(MLXFLAGS)

$(LIBFT_A):
	$(MAKE) -C src/libft

$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C minilibx-linux

fclean:	clean
	rm -f $(NAME)

re:	fclean all
