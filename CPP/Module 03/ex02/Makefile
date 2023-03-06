CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
RM		= rm -rf
NAME	= fragTrap

SRC		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
HEADER	= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJ		= $(patsubst %.cpp,%.o,$(SRC))
OBJDIR	= obj/

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJDIR)*.o -o $(NAME)

%.o:	%.cpp $(HEADER) $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)$@

$(OBJDIR):
	mkdir obj

clean:
	$(RM) $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re