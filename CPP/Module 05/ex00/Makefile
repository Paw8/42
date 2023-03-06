CC			= c++
CFLAGS		= -Wall -Werror -Wextra -g -std=c++98
RM			= rm -rf
NAME		= bureaucrat

SRC			= main.cpp Bureaucrat.cpp myException.cpp
HEADER		= Bureaucrat.hpp myException.hpp

OBJDIR		= obj/
OBJ_NAME	= $(patsubst %.cpp,%.o,$(SRC))
OBJS		= $(addprefix $(OBJDIR), $(OBJ_NAME))	

all:	$(NAME)

$(NAME):	$(OBJDIR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o:	%.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir obj

clean:
	$(RM) $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re