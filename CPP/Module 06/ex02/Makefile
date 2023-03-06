CC			= c++
CFLAGS		= -Wall -Werror -Wextra -g -std=c++98
RM			= rm -rf
NAME		= base

SRCDIR		= src/
SRC			= main.cpp Base.cpp

INCLUDES	= Base.hpp

OBJDIR		= obj/
OBJ_NAME	= $(patsubst %.cpp,%.o,$(SRC))
OBJS		= $(addprefix $(OBJDIR), $(OBJ_NAME))	

all:	$(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp $(SRCDIR)$(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir obj

clean:
	$(RM) $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re