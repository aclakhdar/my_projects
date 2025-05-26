# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 16:45:43 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/25 15:21:59 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp AMateria.cpp\
Character.cpp\
Cure.cpp\
Ice.cpp\
ICharacter.cpp\
list.cpp\
MateriaSource.cpp\

FLAGS = -std=c++98 -g -Wall -Wextra -Werror
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
