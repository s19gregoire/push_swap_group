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

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(INC) -o $(NAME) 

all: $(NAME)

$(LIBFT):
	@cd ./libft && make

clean:
	@rm -f $(OBJS)
	@cd $(LIBFTDIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
