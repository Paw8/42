# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 16:31:48 by pcordeir          #+#    #+#              #
#    Updated: 2022/04/10 17:50:22 by pcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c checkfile.c fdf_utils.c checkfile_utils.c putfile.c\
get_next_line/get_next_line.c get_next_line/get_next_line_utils.c fdf.c

OBJS = $(SRC:.c=.o)
HEADER = -Iget_next_line -Ilibft
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3 
LDFLAGS = -L./libft -lft -L./ -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
NAME = fdf


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(HEADER) -D BUFFER_SIZE=100 $< -o $@

$(NAME): $(OBJS)
	make -C libft all
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	rm -rf $(NAME)
	make -C libft fclean

re: fclean $(NAME)