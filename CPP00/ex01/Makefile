NAME=freak_bible

# Compiler options
CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
RESET  = 	\033[0m

# Folders
OBJ_FOLDER     	= ./obj/

# Files
BANNER = ../../make_banner.sh
GITPUSH = ../../git_push.sh
SRCS = main.cpp Phonebook.cpp Contact.cpp 

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)%.o)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

# Targets
.PHONY: all clean fclean re MSG_START MSG_DONE gp run val

all: MSG_START $(NAME) MSG_DONE

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_FOLDER)%.o: %.cpp
	@mkdir -p $(@D)
	@echo -n "$(GREEN).$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_FOLDER)
	@$(BANNER) $(NAME) "removed object files" "$(RED)"

fclean: clean
	@$(RM) $(NAME)
	@$(BANNER) $(NAME) "removed program" "$(RED)"

re: fclean all

run: all
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

MSG_START:
	@$(BANNER) $(NAME) compiling "$(ORANGE)"

MSG_DONE:
	@$(BANNER) $(NAME) compiled "$(GREEN)"

gp: fclean
	$(GITPUSH) $(NAME)