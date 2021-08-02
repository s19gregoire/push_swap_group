NAME = push_swap

INC = -I./inc

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror

SRC = \
	srcs/main.c \
	srcs/pushswap.c \
	srcs/pushswap_utils.c \
	srcs/stack.c \
	srcs/stack_utils.c \
	srcs/small_sort.c \
	srcs/small_sortutils.c \
	srcs/sort_utils.c \
	srcs/ft_atoi.c

OBJS = 	$(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INC) -o $(NAME) 

all: $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
