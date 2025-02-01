NAME = fractol

# directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
MLXDIR = mlx

# sources
SRCS = main.c \
	init_fractol_type.c init_julia.c init_mlx.c init_event.c \
	handle_event.c render.c indicate_example.c \
	ft_utils.c get_next_line.c

# objects/archives
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
MLX = $(MLXDIR)/libmlx.a

# flags
WFLAG = -Wall -Wextra -Werror
IFLAG = -Iinc -Imlx
LFLAG = -lbsd -lXext -lX11 -lm -Lmlx -lmlx -O3 -march=native

# rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(WFALG) $(OBJS) $(MLX) $(IFLAG) $(LFLAG) -o $(NAME)

clean:
	$(RM) -r $(OBJDIR)
	make -C mlx clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

$(MLX):
	make -C mlx

.PHONY: all clean fclean re
