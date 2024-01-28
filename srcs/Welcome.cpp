#include "../includes/Server.hpp"

void Server::welcomeMessage(Client * client) {
	client->receiveMessage("");
	client->receiveMessage("██████╗ ██╗   ██╗██████╗  ██████╗ ██╗     ██████╗ ██╗  ██╗");
	client->receiveMessage("██╔══██╗██║   ██║██╔══██╗██╔═══██╗██║     ██╔══██╗██║  ██║");
	client->receiveMessage("██████╔╝██║   ██║██║  ██║██║   ██║██║     ██████╔╝███████║");
	client->receiveMessage("██╔══██╗██║   ██║██║  ██║██║   ██║██║     ██╔═══╝ ██╔══██║");
	client->receiveMessage("██║  ██║╚██████╔╝██████╔╝╚██████╔╝███████╗██║     ██║  ██║");
	client->receiveMessage("╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝╚═╝     ╚═╝  ╚═╝");
	client->receiveMessage("                            welcome to RUDOLPH irc, Enjoy!");
	client->receiveMessage("                                      " + time(1));
}


void Server::welcomeServer()
{
	std::string text;
	text += "\n";
	text += "██████╗ ██╗   ██╗██████╗  ██████╗ ██╗     ██████╗ ██╗  ██╗\n";
	text += "██╔══██╗██║   ██║██╔══██╗██╔═══██╗██║     ██╔══██╗██║  ██║\n";
	text += "██████╔╝██║   ██║██║  ██║██║   ██║██║     ██████╔╝███████║\n";
	text += "██╔══██╗██║   ██║██║  ██║██║   ██║██║     ██╔═══╝ ██╔══██║\n";
	text += "██║  ██║╚██████╔╝██████╔╝╚██████╔╝███████╗██║     ██║  ██║\n";
	text += "╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝╚═╝     ╚═╝  ╚═╝\n";
	text += "                            welcome to RUDOLPH irc, Enjoy!\n";
	text += "                                      " + getCreateTime() + "\n";
	std::cout << text;
}