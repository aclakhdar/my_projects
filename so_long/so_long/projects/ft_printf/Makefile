# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aclakhda <aclakhda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:14:54 by aclakhda          #+#    #+#              #
#    Updated: 2023/12/08 17:38:46 by aclakhda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = ft_printf.c ft_printhex.c ft_putptr.c ft_putchar.c ft_putnbr.c \
		ft_putstr.c ft_putun.c ft_strlen.c
OBJT = $(SRC:.c=.o)
HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJT)
	@ar -rcs $(NAME) $(OBJT)
%.o: %.c
	@cc $(FLAGS) -I $(HEADER) -c $<
clean:
	@rm -rf $(OBJT)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
