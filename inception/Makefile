RED			= \033[0m\033[91m
GREEN		= \033[0m\033[92m
UNDO_COL	= \033[0m

SU          = sudo
DOCKER      = docker
COMPOSE     = compose
VOLUME      = volume
IMAGE       = image
FLAGS       = --file
BUILD       = --build
DETACHED    = -d
RM          = rm -f
RRM         = rm -rf

SRC         = srcs/docker-compose.yml
LIBS        = ./srcs/
LOCAL       = /home/pedro/data/
ARG         = srcs_vol_maria srcs_vol_wp

NAME        = Inception
rwildcard   = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

$(NAME): $(call rwildcard,$(LIBS),*)
	$(DOCKER) $(COMPOSE) $(FLAGS) $(SRC) up $(BUILD) $(DETACHED)
	@touch $(NAME)
	@echo "$(GREEN)<<<<<<<<<< $(NAME) was created! >>>>>>>>>>$(UNDO_COL)"

stop:
	$(DOCKER) $(COMPOSE) $(FLAGS) $(SRC) down

run:
	$(DOCKER) $(COMPOSE) $(FLAGS) $(SRC) up $(DETACHED)

clean: stop
	$(DOCKER) $(VOLUME) $(RM) $(ARG)
	@echo "$(RED)<<<<<<<<<< Volumes removed! >>>>>>>>>>$(UNDO_COL)"

fclean: clean
	$(SU) $(RRM) $(LOCAL)wordpress/*
	$(SU) $(RRM) $(LOCAL)mariadb/*
	$(RM) $(NAME)
	@echo "$(RED)<<<<<<<<<< Local data removed! >>>>>>>>>>$(UNDO_COL)"

re: fclean $(NAME)
	