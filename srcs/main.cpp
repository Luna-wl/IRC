#include <iostream>

#include "Server.hpp"
#include "Color.hpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cerr << YELLOW << "using : ./ircserv <port> <passwd>" << DEFAULT << std::endl;
		return (1);
	}

	Server server(argv[1], argv[2]);
	if (server.start() != 0)
		return (1);
	server.server_loop();	
	return (0);
}