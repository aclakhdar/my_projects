# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 01:44:16 by aclakhda          #+#    #+#              #
#    Updated: 2024/02/22 16:13:21 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV = server
CLT = client
SRC = utils.c
OBJ = $(SRC:.c=.o)
LIB = libftprintf.a
PATH = ./ft_printf/$(LIB)
FLAGS = -Wall -Wextra -Werror

all: $(SRV) $(CLT)

$(SRV): server.c $(OBJ)
	cc $(FLAGS) server.c $(OBJ) $(PATH) -o $(SRV)

$(CLT): client.c $(OBJ)
	cc $(FLAGS) client.c $(OBJ) $(PATH) -o $(CLT)

$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC) -o $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(SRV) $(CLT)

re: fclean all

.PHONY: all clean fclean re
