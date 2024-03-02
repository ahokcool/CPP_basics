NAME=theBestJob

# Compiler options
CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Colors
RED    = 	\033[0;31m
GREEN  = 	\033[0;32m
ORANGE = 	\033[0;33m
BLUE   = 	\033[0;34m
RESET  = 	\033[0m

# Folders
OBJ_FOLDER     	= ./obj/

# Files
BANNER = ../../make_banner.sh
GITPUSH = ../../git_push.sh
SRCS = tests.cpp Account.cpp
ORIGINAL_LOG = 19920104_091532.log
TEST_FILES = test.log mine_no_stamps.log original_no_stamps.log

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_FOLDER)%.o)

#++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++#

# Targets
.PHONY: all clean fclean re MSG_START MSG_DONE gp run val test

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
	@$(RM) $(TEST_FILES)
	@$(BANNER) $(NAME) "removed test files" "$(RED)"

fclean: clean
	@$(RM) $(NAME)
	@$(BANNER) $(NAME) "removed program" "$(RED)"

re: fclean all

run: all
	@./$(NAME)

val: all
	@valgrind --leak-check=full ./$(NAME)

test: re
	@$(BANNER) $(NAME) "creating log file..." "$(ORANGE)"
	@./$(NAME) > test.log
	@cat test.log
	@$(BANNER) $(NAME) "removing timestamps in log files..." "$(BLUE)"
	@$(BANNER) $(NAME) "original log..." "$(ORANGE)"
	@sed 's/\[[0-9]\{8\}_[0-9]\{6\}\] //' $(ORIGINAL_LOG) > original_no_stamps.log
	@cat original_no_stamps.log
	@$(BANNER) $(NAME) "my log..." "$(ORANGE)"
	@sed 's/\[[0-9]\{8\}_[0-9]\{6\}\] //' test.log > mine_no_stamps.log
	@cat mine_no_stamps.log
	@diff_output=$$(diff mine_no_stamps.log original_no_stamps.log); \
	if [ -z "$$diff_output" ]; then \
	    $(BANNER) $(NAME) "running diff..." "$(GREEN)"; \
	    echo "$(GREEN) The two files are (besides the timestamp) identical! $(RESET)"; \
	else \
	    $(BANNER) $(NAME) "running diff..." "$(ORANGE)"; \
	    echo "$$diff_output"; \
	fi


MSG_START:
	@$(BANNER) $(NAME) compiling "$(ORANGE)"

MSG_DONE:
	@$(BANNER) $(NAME) compiled "$(GREEN)"

gp: fclean
	$(GITPUSH) $(NAME)