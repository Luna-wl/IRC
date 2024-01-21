NAME = ircserv

SRCS_DIR := ./srcs/
SRCS := Client.cpp \
		main.cpp \
		Parser.cpp \
		Server.cpp \
		Server_util.cpp \
		Channel.cpp 


CMD_DIR := ./srcs/command/
CMD := 	Nick.cpp \
		List.cpp \
		Invite.cpp \
		Pass.cpp \
		Topic.cpp \
		User.cpp \
		Join.cpp \
		PrivMsg.cpp \
		Command.cpp \
    Quit.cpp \
		Names.cpp \
		Part.cpp \
		Kick.cpp \
		Notice.cpp \
		Oper.cpp \
		Mode.cpp \
		Time.cpp \
		Ping.cpp \
		Pong.cpp

CC = g++

CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=address

CPPFLAGS = -std=c++98

OBJ_DIR = ./obj/

OBJS = ${addprefix $(OBJ_DIR), $(SRCS:.cpp=.o)} \
		${addprefix $(OBJ_DIR), $(CMD:.cpp=.o)}

RM = rm -rf

BRED =\033[1;31m
BGRN =\033[1;32m
BYEL =\033[1;33m
BBLU =\033[1;34m
BMAG =\033[1;35m
BCYN =\033[1;36m
RES = \033[0m

CLEAN = echo "$(BRED)Clean.....$(RES)"

${OBJ_DIR}%.o: ${SRCS_DIR}%.cpp
	@printf "$(BGRN)\rCompiling $(BYEL)$< "
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

${OBJ_DIR}%.o: ${CMD_DIR}%.cpp
	@printf "$(BGRN)\rCompiling commands $(BYEL)$< "
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

all: ${OBJ_DIR} ${NAME}

${OBJ_DIR}:
	@mkdir -p $(OBJ_DIR)

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) $(CPPFLAG) $(OBJS) -o $(NAME)
	@echo "\n$(BMAG) .----------------.  .----------------.  .------------------.  .----------------."
	@echo "$(BMAG)| .--------------. || .--------------. || .---------------. || .--------------. |"
	@echo "$(BMAG)| |  $(BCYN)________$(BMAG)    | || |    $(BCYN) ____ $(BMAG)    | || |  $(BCYN)____  _____ $(BMAG) | || | $(BCYN) _________ $(BMAG)  | |"
	@echo "$(BMAG)| | $(BCYN)|_   ___ \`.$(BMAG)  | || |  $(BCYN) .'    \`.$(BMAG)   | || | $(BCYN)|_   \\|_   _|$(BMAG) | || | $(BCYN)|_   ___  |$(BMAG)  | |"
	@echo "$(BMAG)| |   $(BCYN)| |   \`. \\ $(BMAG)| || |  $(BCYN)/  .--.  \\  $(BMAG)| || |   $(BCYN)|   \\ | | $(BMAG)  | || | $(BCYN)  | |_  \\_| $(BMAG) | |"
	@echo "$(BMAG)| |   $(BCYN)| |    | |$(BMAG) | || |  $(BCYN)| |    | |$(BMAG)  | || |   $(BCYN)| |\\ \\| | $(BMAG)  | || | $(BCYN)  |  _|  _  $(BMAG) | |"
	@echo "$(BMAG)| | $(BCYN) _| |___.' /$(BMAG) | || |  $(BCYN)\\  \`--'  / $(BMAG) | || |  $(BCYN)_| |_\\   |_$(BMAG)  | || | $(BCYN) _| |___/ | $(BMAG) | |"
	@echo "$(BMAG)| | $(BCYN)|________.'$(BMAG)  | || |   $(BCYN)\`.____.'$(BMAG)   | || | $(BCYN)|_____|\____|$(BMAG) | || | $(BCYN)|_________| $(BMAG) | |"
	@echo "$(BMAG)| |              | || |              | || |               | || |              | |"
	@echo "$(BMAG)| '--------------' || '--------------' || '---------------' || '--------------' |"
	@echo "$(BMAG)  '----------------'  '----------------'  '-----------------'  '---------------'"

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) *.dSYM

fclean: clean
	@clear
	@$(RM) $(NAME) $(OBJ_DIR)
	@$(CLEAN)

re: fclean all

.PHONY: all clean fclean re