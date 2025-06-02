# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpascal <dpascal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 07:58:00 by dpascal           #+#    #+#              #
#    Updated: 2025/05/26 07:58:01 by dpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= g++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
NAME	= fixed

SRCS	= main.cpp \
Fixed.cpp \

OBJS	= $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
