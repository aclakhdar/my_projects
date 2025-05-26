# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/18 15:28:19 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/18 15:47:07 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = HumanA.cpp \
	  HumanB.cpp \
	  Weapon.cpp \
	  main.cpp
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++
NAME = program
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(Flags) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	c++ $(Flags) -c $(SRC)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
