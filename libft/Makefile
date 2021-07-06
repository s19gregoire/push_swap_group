# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 18:36:32 by mlazzare          #+#    #+#              #
#    Updated: 2021/05/08 10:37:26 by mlazzare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = ./

SRC	=	ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memccpy.c			\
		ft_memmove.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strlen.c				\
		ft_numlen.c				\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strnstr.c			\
		ft_strcmp.c			\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_isspace.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_lstnew.c		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c	\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c		\

OBJS = $(SRC:%.c=%.o)

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $(SRC)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
