CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf
NAME	= clapTrap

SRC		= main.cpp ClapTrap.cpp
HEADER	= ClapTrap.hpp
OBJ		= $(patsubst %.cpp,%.o,$(SRC))

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:	%.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re