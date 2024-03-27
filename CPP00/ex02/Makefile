NAME=theBestJob

# Compiler options
CC = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98
RM = rm -rf

# Colors
RED    = 	"\033[0;31m"
GREEN  = 	"\033[0;32m"
ORANGE = 	"\033[0;33m"
BLUE   = 	"\033[0;34m"
RESET  = 	"\033[0m"

# Folders
OBJ_FOLDER     	= ./obj/

# Files
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
	@echo $(RED) $(NAME) "removed object files" $(RESET)
	@$(RM) $(TEST_FILES)
	@echo $(RED) $(NAME) "removed test files" $(RESET)

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

test: re
	@echo $(ORANGE) $(NAME) "creating log file..." $(RESET)
	@./$(NAME) > test.log
	@cat test.log
	@echo $(ORANGE) $(NAME) "removing timestamps in log files..." $(RESET)
	@echo $(ORANGE) $(NAME) "original log..." "$(ORANGE)"
	@sed 's/\[[0-9]\{8\}_[0-9]\{6\}\] //' $(ORIGINAL_LOG) > original_no_stamps.log
	@cat original_no_stamps.log
	@echo $(ORANGE) $(NAME) "my log..." "$(ORANGE)"
	@sed 's/\[[0-9]\{8\}_[0-9]\{6\}\] //' test.log > mine_no_stamps.log
	@cat mine_no_stamps.log
	@diff_output=$$(diff mine_no_stamps.log original_no_stamps.log); \
	if [ -z "$$diff_output" ]; then \
		echo $(ORANGE) $(NAME) "running diff..." "$(ORANGE)"; \
	    echo "$(GREEN) The two files are (besides the timestamp) identical! $(RESET)"; \
	else \
		echo $(ORANGE) $(NAME) "running diff..." "$(ORANGE)"; \
	    echo "$$diff_output"; \
	fi


MSG_START:
	@echco $(ORANGE) $(NAME) "compiling" $(RESET)

MSG_DONE:
	@echo $(GREEN) $(NAME) "compiled" $(RESET)

gp: fclean
	$(GITPUSH) $(NAME)