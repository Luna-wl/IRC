#include "../includes/Server.hpp"

void Server::welcomeMessage(Client * client) {
	client->recieveMessage("██████╗ ██╗   ██╗██████╗  ██████╗ ██╗     ██████╗ ██╗  ██╗");
	client->recieveMessage("██╔══██╗██║   ██║██╔══██╗██╔═══██╗██║     ██╔══██╗██║  ██║");
	client->recieveMessage("██████╔╝██║   ██║██║  ██║██║   ██║██║     ██████╔╝███████║");
	client->recieveMessage("██╔══██╗██║   ██║██║  ██║██║   ██║██║     ██╔═══╝ ██╔══██║");
	client->recieveMessage("██║  ██║╚██████╔╝██████╔╝╚██████╔╝███████╗██║     ██║  ██║");
	client->recieveMessage("╚═╝  ╚═╝ ╚═════╝ ╚═════╝  ╚═════╝ ╚══════╝╚═╝     ╚═╝  ╚═╝");
	client->recieveMessage("                            welcome to RUDOLPH irc, Enjoy!");
	client->recieveMessage("                                      " + time(1));
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