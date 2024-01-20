NAME = ircserv

SRC =	srcs/main.cpp \
		srcs/Server.cpp \
		srcs/Server_util.cpp \
		srcs/Client.cpp \
		srcs/Parser.cpp \
		srcs/Channel.cpp \
		srcs/command/Command.cpp \
		srcs/command/Nick.cpp	\
		srcs/command/Pass.cpp \
		srcs/command/User.cpp \
		srcs/command/Join.cpp \
		srcs/command/Invite.cpp \
		srcs/command/PrivMsg.cpp \
		srcs/command/Quit.cpp \
		srcs/command/Names.cpp \
		srcs/command/Part.cpp \
		srcs/command/Kick.cpp \
		srcs/command/Notice.cpp \
		srcs/command/Oper.cpp \
		srcs/command/Mode.cpp

INCLUDES = ./includes

HEADER = includes/Channel.hpp \
		includes/Client.hpp \
		includes/Color.hpp \
		includes/Command.hpp \
		includes/Parser.hpp \
		includes/Replies.hpp \
		includes/Server.hpp

CC = g++

CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=address

CPPFLAGS = -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%o: %cpp
	@$(CC) $(CFLAG) -I $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	@printf "$(GREEN)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -I $(INCLUDES) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@clear
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
