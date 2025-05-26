SRC = main.cpp contact.cpp PhoneBook.cpp
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++
NAME = phonebook

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
fclean:
	@rm -rf $(NAME)
re: fclean all

.PHONY: all fclean re
