# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 14:07:12 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/25 15:25:33 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Cat.cpp Dog.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++
NAME = program
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	c++ $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re

