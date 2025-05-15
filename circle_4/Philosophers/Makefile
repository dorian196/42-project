
CC = gcc -g 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
SRCS = src/philosophers.c \
core/check_arg.c \
core/checker.c \
core/eat.c \
core/fork.c \
core/free.c \
core/init_var.c \
core/print_msg.c \
core/process.c \
core/sleep.c \
core/timer.c \
core/utils.c \


OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
