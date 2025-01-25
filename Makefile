NAME = fractol

# directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
MLXDIR = mlx

# sources
SRCS_NAME = main.c init_fractol.c init_mlx.c event.c render.c ft_utils.c exit.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCS_NAME))

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

$(OBJDIR)/%.o:%.c
	mkdir -p $(@D)
	$(CC) $(WFLAG) $(IFLAG) -c $< -o $@

$(MLX):
	make -C mlx

.PHONY: all clean fclean re
