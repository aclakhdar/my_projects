# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/20 13:00:01 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/23 16:34:28 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++
NAME = FragTrap
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

