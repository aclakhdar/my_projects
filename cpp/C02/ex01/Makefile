# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 16:15:16 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/22 13:47:39 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Fixed.cpp
FLAGS = -std=c++98 -Wall -Wextra -Werror
CC = c++
NAME = fixed
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
