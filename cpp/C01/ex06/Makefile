# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 14:17:57 by aclakhda          #+#    #+#              #
#    Updated: 2025/05/18 16:42:26 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.cpp Harl.cpp
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
