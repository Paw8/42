CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf
NAME	= harlFilter

SRC		= main.cpp Harl.cpp
HEADER	= Harl.hpp
OBJ		= $(patsubst %.cpp,%.o,$(SRC))

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re