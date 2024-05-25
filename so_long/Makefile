ARCHIVE = lib.a
CC = cc
FLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -framework OpenGL -framework Appkit
SRC_FILE = so_long.c projects/ft_printf/ft_printf.c projects/ft_printf/ft_printhex.c projects/ft_printf/ft_putchar.c projects/ft_printf/ft_putnbr.c \
projects/ft_printf/ft_putptr.c projects/ft_printf/ft_putstr.c projects/ft_printf/ft_putun.c projects/get_next_line/get_next_line_utils.c \
projects/get_next_line/get_next_line.c utils/check_path.c utils/check_pec.c utils/dup_map.c \
utils/map_checker.c utils/map_content.c utils/map.c utils/path_to_ex.c utils/player_xy.c \
utils/print_and_ex.c utils/strlen_of_line.c  utils/wall_checker.c mlx/import_image.c mlx/map_cord.c \
mlx/put_image.c mlx/window.c utils/ft_memset.c utils/ft_strncmp.c utils/the_hight_of_map.c \
mlx/counter_collection.c mlx/event_hand.c mlx/deraction.c mlx/import.c\
mlx/put.c
OBJ = *.o
NAME = so_long

all: $(NAME)

$(OBJ): $(SRC_FILE)
	$(CC) $(FLAGS) -c $(SRC_FILE)
$(NAME): $(OBJ)
	$(CC) $(LIBS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
