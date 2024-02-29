NAME=megaphone

# Compiler options
CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98 -fsanitize=address
RM = rm -rf

# Colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[34m
PURPLE = 	\033[35m
RESET  = 	\033[0m

# Folders
INCLUDE_FOLDER 	= ./includes/
SRC_FOLDER     	= ./src/
OBJ_FOLDER     	= ./obj/

# Files
BANNER = ../../make_banner.sh
SRCS = $(addprefix $(SRC_FOLDER), 	\
	megaphone.cpp					\
	)

# Object files
OBJS = $(SRCS:$(SRC_FOLDER)%.cpp=$(OBJ_FOLDER)%.o)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

# Targets
.PHONY: all clean fclean re

all: MSG_START $(NAME) MSG_DONE

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	@mkdir -p $(@D)
	@echo -n "$(BLUE).$(RESET)"
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