CC = cc -fsanitize=address
FLAGS = -Wall -Wextra -Werror
SRC = push_swap.c utils/printf_and_ex.c utils/check_arg.c libft_utils/ft_split.c libft_utils/ft_substr.c\
libft_utils/ft_strlen.c libft_utils/ft_atoi.c libft_utils/ft_digit.c utils/comp.c utils/fill_stack.c\
utils/sort.c utils/ft_free_stack.c utils/simple_sort.c utils/utils_1.c utils/simple_sort_2.c\
libft_utils/ft_strjoin.c utils/algh_sort.c libft_utils/ft_sqrt.c utils/sort_rr.c utils/algh_sort_utils.c\
utils/algh_sort_u2.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
