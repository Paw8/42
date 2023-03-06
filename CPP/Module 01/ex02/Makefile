CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf
NAME	= reference

SRC		= main.cpp
OBJ		= $(patsubst %.cpp,%.o,$(SRC))

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re