NAME=megaphone

# Compiler options
CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address
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
SRCS = megaphone.cpp

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)%.o)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

# Targets
.PHONY: all clean fclean re MSG_START MSG_DONE gp

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

MSG_START:
	@$(BANNER) $(NAME) compiling "$(ORANGE)"

MSG_DONE:
	@$(BANNER) $(NAME) compiled "$(GREEN)"

gp: fclean
	@$(BANNER) $(NAME) "commiting and pushing to git... " "$(ORANGE)"
	@echo "---"
	@git status
	@echo "---"
	@git add .
	@git commit -m "auto commit:  $(NAME)"
	@git push
	@echo "---"
	@git status
	@echo "---"
	
	@$(BANNER) $(NAME) "!GP DONE!"$(ORANGE)"