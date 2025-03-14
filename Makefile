CC = cc
CFLAGS = -Wextra -Werror -Wall -g3
MLXFLAGS = -lX11 -lXext -lm -lGL -lz
LIBFT_A = src/libft/libft.a
MLX = minilibx-linux/libmlx.a
OBJDIR = .obj
SRCS =	parsing.c utils.c bresenham.c main.c lib_utils.c
OBJS =	$(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
NAME =	fdf

all: $(NAME)


$(OBJDIR)/%.o: src/%.c src/libft/libft.h minilibx-linux/mlx.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile $(LIBFT_A) $(MLX)
	cc $(OBJS) -o $(NAME) $(LIBFT_A) $(MLX) $(MLXFLAGS)

$(LIBFT_A):
	$(MAKE) -C src/libft

$(MLX):
	$(MAKE) -C minilibx-linux

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C minilibx-linux

fclean:	clean
	rm -f $(NAME)

re: fclean all
