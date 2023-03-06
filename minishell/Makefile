# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 09:28:08 by pcordeir          #+#    #+#              #
#    Updated: 2022/07/11 00:19:44 by mokatova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g
RM			= 	rm -rf

SRC			=	clean_n_free.c echo.c error_management.c error_utils.c exit.c \
				fill_the_struct.c builtin.c here_doc_utils.c main.c \
				parse_utils.c parse_utils2.c read_dollar.c redirect_tools.c \
				run_cmd_utils.c running_the_commands.c save_env.c \
				skipping_symbols.c str_char_str.c signal_handling.c unset.c \
				export.c cd.c run_cmd_utils2.c
LIBFT		= 	Libft/libft.a
LIBFLAGS	= 	-L./Libft -lft
RDLINE_H	= 	-I/usr/local/opt/readline/include/
RDLINEFLAGS	= 	-L/usr/local/opt/readline/lib -lreadline

OBJ			= 	$(SRC:.c=.o)

NAME		= 	minishell

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $(RDLINE_H) $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) $(RDLINEFLAGS) -o $(NAME)

$(LIBFT):
	make -C Libft all

clean:
	$(RM) $(OBJ)
	make -C Libft clean

fclean: clean
	$(RM) $(NAME)
	make -C Libft fclean

re: fclean all
