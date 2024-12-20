# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 14:18:28 by aclakhda          #+#    #+#              #
#    Updated: 2024/12/19 14:23:39 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc  -Wall -Werror -Wextra #-fsanitize=thread #-g3
SRC = main.c checker.c init.c routine.c utils.c print.c monitoring.c actions.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $^
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
