#
#
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m

NAME = main
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
MLX_DIR = mlx_fdf
LIBFT_DIR = libft
GNL_DIR = get_next_line

SRCS = main.c utils.c fdf_dda.c dda_helpers.c line_drawing_functs.c smol_functions.c \
		$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME) $(FRAMEWORKS) -L$(MLX_DIR) -lmlx
	@echo ""
	@echo "$(GREEN)  █████▒▓█████▄   █████▒"
	@echo "▓██   ▒ ▒██▀ ██▌▓██   ▒ "
	@echo "▒████ ░ ░██   █▌▒████ ░ "
	@echo "░▓█▒  ░ ░▓█▄   ▌░▓█▒  ░ "
	@echo "░▒█░    ░▒████▓ ░▒█░    "
	@echo " ▒ ░     ▒▒▓  ▒  ▒ ░    "
	@echo " ░       ░ ▒  ▒  ░      "
	@echo " ░ ░     ░ ░  ░  ░ ░    "
	@echo "           ░            "
	@echo "         ░              "
	@echo "Created: $(words $(OBJS)) object file(s) for FDF"
	@echo "Created: $(NAME)$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	@$(MAKE) -C $(MLX_DIR)

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME) 
	@rm -f $(MLX_DIR)/libmlx.a
	@rm -f $(LIBFT_DIR)/libft.a
	@echo ""
	@echo "$(YELLOW)  █████▒▓█████▄   █████▒"
	@echo "▓██   ▒ ▒██▀ ██▌▓██   ▒ "
	@echo "▒████ ░ ░██   █▌▒████ ░ "
	@echo "░▓█▒  ░ ░▓█▄   ▌░▓█▒  ░ "
	@echo "░▒█░    ░▒████▓ ░▒█░    "
	@echo " ▒ ░     ▒▒▓  ▒  ▒ ░    "
	@echo " ░       ░ ▒  ▒  ░      "
	@echo " ░ ░     ░ ░  ░  ░ ░    "
	@echo "           ░            "
	@echo "         ░              "
	@echo "Removed: $(words $(OBJS)) object file(s) for FDF"
	@echo "Removed: $(NAME)$(RESET)"
    
re: fclean all

mlx:
	@$(MAKE) -C $(MLX_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

.PHONY: all clean fclean re mlx libft