# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 22:25:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/05/13 20:05:39 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC = -I./inc

CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address

SRC = \
	srcs/main.c \
	srcs/pushswap.c \
	srcs/pushswap_utils.c \
	srcs/stack.c \
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