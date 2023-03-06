# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcordeir <pcordeir@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 09:28:08 by pcordeir          #+#    #+#              #
#    Updated: 2022/04/20 11:53:25 by pcordeir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -rf

C_SRC		= client.c
S_SRC		= server.c
LIBFT		= libft/libft.a
LIBFLAGS	= -L./libft -lft

C_OBJ		= $(C_SRC:.c=.o)
S_OBJ		= $(S_SRC:.c=.o)

C_NAME		= client
S_NAME		= server

all: $(C_NAME) $(S_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(C_NAME): $(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(C_OBJ) $(LIBFLAGS) -o $(C_NAME)

$(S_NAME): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIBFLAGS) -o $(S_NAME)

$(LIBFT):
	make -C libft all

clean:
	$(RM) $(C_OBJ) $(S_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(C_NAME) $(S_NAME)
	make -C libft fclean

re: fclean all
