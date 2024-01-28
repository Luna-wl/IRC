#include <iostream>
#include <signal.h>

#include "../includes/Server.hpp"

void signalHandler( int signum ) {
	std::cout << "\nInterrupt signal (" << signum << ") received.\n";
	Server::set_state(false);
}

int main(int argc, char **argv)
{
	signal(SIGINT, signalHandler);
	if (argc != 3 || argv[1][0] == '\0' || argv[2][0] == '\0')
	{
		std::cerr << YELLOW << "using : ./ircserv <port> <passwd>" << DEFAULT << std::endl;
		return (1);
	}

	Server server(argv[1], argv[2]);
	if (server.start() != 0)
		return (1);
	server.serverLoop();
	return (0);
}