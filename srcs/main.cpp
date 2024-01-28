#include <iostream>

#include "../includes/Server.hpp"
#include "../includes/Color.hpp"

void signalHandler( int signum ) {
   std::cout << "Interrupt signal (" << signum << ") received.\n";

	Server::set_state(false);
   // cleanup and close up stuff here  
   // terminate program  

}

int main(int argc, char **argv) {
	signal(SIGINT, signalHandler);
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