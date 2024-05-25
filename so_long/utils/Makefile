NAME		= utils.a
CFLAGS		= -Wall -Werror -Wextra
FILES		= check_path.c check_pec.c dup_map.c map_checker.c map_content.c \
	map.c path_to_ex.c player_xy.c print_and_ex.c strlen_of_line.c \
	the_hight_of_map.c wall_checker.c
OBJ			= $(FILES:.c=.o)
CC 			= cc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $?

%.o: %.c
	$(CC) $(CFLAGS) -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all