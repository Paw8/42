# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 10:24:24 by pcordeir          #+#    #+#              #
#    Updated: 2022/03/18 12:18:41 by pcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c csidu.c xXp.c

OBJS = $(SRC:.c=.o)
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	ar crs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
