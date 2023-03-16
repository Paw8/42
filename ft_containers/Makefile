RED			= \033[0m\033[91m
GREEN		= \033[0m\033[92m
UNDO_COL	= \033[0m
CC			= c++
CFLAGS		= -Wall -Werror -Wextra -g -std=c++98
RM			= rm -rf
NAME		= ft_containers

SRCDIR		= src/
SRC			= main.cpp

INCL_NAME	= bidirectional_iterator.hpp iterator_traits.hpp iterator.hpp map.hpp pair.hpp redblacktree.hpp reverse_iterator.hpp set.hpp stack.hpp utils.hpp vector.hpp 
INCLUDES	= $(addprefix $(SRCDIR), $(INCL_NAME))

OBJDIR		= obj/
OBJ_NAME	= $(patsubst %.cpp,%.o,$(SRC))
OBJS		= $(addprefix $(OBJDIR), $(OBJ_NAME))

all:	$(NAME)

$(NAME):	$(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)SUCCESSFULLY CREATED FT_CONTAINERS!$(UNDO_COL)"

$(OBJDIR)%.o:	$(SRCDIR)%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir obj

clean:
	$(RM) $(OBJDIR)

fclean:	clean
	$(RM) $(NAME)
	@echo "$(RED)Finished cleaning up$(UNDO_COL)"

re:	fclean all

.PHONY:	all clean fclean re
