# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 11:21:58 by pcordeir          #+#    #+#              #
#    Updated: 2022/02/15 10:59:35 by pcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	checkall.c ft_libft.c llist.c main.c push_swap.c rotate.c sortbig.c \
			sorting.c swappush.c
OBJS	= 	$(SRC:.c=.o)
HEADER	= 	push_swap.h
CC		= 	gcc
CFLAGS	= 	-Wall -Werror -Wextra -g
NAME	= 	push_swap

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) $(HEADER) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
