NAME=ex01

# Compiler options
CC 			= c++
CXXFLAGS	= -g -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

# Colors
RED    		= "\033[0;31m"
GREEN  		= "\033[0;32m"
ORANGE 		= "\033[0;33m"
BLUE   		= "\033[0;34m"
RESET  		= "\033[0m"

# Folders
OBJ_FOLDER	= ./obj/

# Files
GITPUSH 	= ../../git_push.sh
SRCS 		= main.cpp Data.cpp

# Object files
OBJS 		= $(SRCS:%.cpp=$(OBJ_FOLDER)%.o)

# Targets
.PHONY: all clean fclean re MSG_START MSG_DONE gp run val lol

all: MSG_START $(NAME) MSG_DONE

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CXXFLAGS) -o $(NAME)
	@echo $(GREEN)"\n Linking complete!"$(RESET)

$(OBJ_FOLDER)%.o: %.cpp
	@mkdir -p $(@D)
	@echo -n $(GREEN)"."$(RESET)
	@$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FOLDER)
	@echo $(RED) $(NAME) "removed object files" $(RESET)

fclean: clean
	@$(RM) $(NAME)
	@echo $(RED) $(NAME) "removed program" $(RESET)

re: fclean all

run: re
	@echo $(BLUE) $(NAME) "starting..." $(RESET)
	@./$(NAME)

val: re
	@echo $(BLUE) $(NAME) "starting with valgrind..." $(RESET)
	@valgrind --leak-check=full ./$(NAME)

MSG_START:
	@echo $(ORANGE) $(NAME) "compiling" $(RESET)

MSG_DONE:
	@echo $(GREEN) $(NAME) "compiled" $(RESET)

gp: fclean
	@echo -n "Enter a commit message: $(NAME): " && \
	read COMMIT_MSG && \
	$(GITPUSH) "$(NAME): $$COMMIT_MSG"

lol:
	curl parrot.live