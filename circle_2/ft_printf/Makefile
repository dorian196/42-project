# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/04 03:00:01 by dpascal           #+#    #+#              #
#    Updated: 2024/05/10 00:03:39 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_putstr.c \
ft_putnbr.c ft_p_adress.c \
ft_uputnbr.c ft_printf.c \
ft_strlen.c ft_putnbr_adr.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)
	
fclean:	clean
	rm -f $(NAME)
	
re:	fclean all

.PHONY: all clean fclean re
