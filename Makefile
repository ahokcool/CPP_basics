# Makefile just to push the code to the git repository

GITPUSH = ./git_push.sh

gp:
	@echo -n "Enter a commit message: $(NAME): " && \
	read COMMIT_MSG && \
	$(GITPUSH) "$(NAME): $$COMMIT_MSG"