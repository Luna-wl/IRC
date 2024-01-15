NAME = ircserv

SRC =	srcs/main.cpp \
		srcs/Server.cpp \
		srcs/Server_util.cpp \
		srcs/Client.cpp \
		srcs/Parser.cpp \
		srcs/Command.cpp \
		srcs/Nick.cpp	\
		srcs/Pass.cpp
INCLUDES = -I ./includes

CC = g++

CFLAGS = -Wall -Wextra -Werror # -g -fsanitize=address

CPPFLAGS = -std=c++98

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%o: %cpp
	@$(CC) $(CFLAG) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ)
	@printf "$(GREEN)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@clear
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
