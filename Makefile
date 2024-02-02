NAME = push_swap

SRC = algo/algo.c algo/cout.c algo/index.c algo/less_than_4.c algo/less_than_6.c algo/utils.c operations/push_a.c operations/push_b.c operations/reverse_rotate.c operations/rotate.c \
operations/swap.c push_swap_main.c parsing/check_args.c parsing/utils_parsing.c parsing/error_managment.c parsing/ini_list.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = includes/libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re