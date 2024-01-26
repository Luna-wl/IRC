#include "../includes/Server.hpp"

void Server::welcomeMessage(Client * client) {
	client->recieveMessage(".-=~=-.                                                                  .-=~=-.");
	client->recieveMessage("(__  _)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.--(__  _)");
	client->recieveMessage("(_ ___)                                                                  (_ ___)");
	client->recieveMessage("( _ __)     █     █░▓█████  ██▓    ▄████▄  ▒█████   ███▄ ▄███▓▓█████     ( _ __)");
	client->recieveMessage("(__  _)    ▓█░ █ ░█░▓█   ▀ ▓██▒   ▒██▀ ▀█ ▒██▒  ██▒▓██▒▀█▀ ██▒▓█   ▀     (__  _)");
	client->recieveMessage("(_ ___)    ▒█░ █ ░█ ▒███   ▒██░   ▒▓█    ▄▒██░  ██▒▓██    ▓██░▒███       (_ ___)");
	client->recieveMessage("(__  _)    ░█░ █ ░█ ▒▓█  ▄ ▒██░   ▒▓▓▄ ▄██▒██   ██░▒██    ▒██ ▒▓█  ▄     (__  _)");
	client->recieveMessage("(_ ___)    ░░██▒██▓ ░▒████▒░██████▒ ▓███▀ ░ ████▓▒░▒██▒   ░██▒░▒████▒    (_ ___)");
	client->recieveMessage("(__  _)    ░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░ ░▒ ▒  ░ ▒░▒░▒░ ░ ▒░   ░  ░░░ ▒░ ░    (__  _)");
	client->recieveMessage("(_ ___)      ▒ ░ ░   ░ ░  ░░ ░ ▒  ░ ░  ▒    ░ ▒ ▒░ ░  ░      ░ ░ ░  ░    (_ ___)");
	client->recieveMessage("(__  _)      ░   ░     ░     ░ ░  ░       ░ ░ ░ ▒  ░      ░      ░       (__  _)");
	client->recieveMessage("(_ ___)        ░       ░  ░    ░  ░ ░         ░ ░         ░      ░  ░    (_ ___)");
	client->recieveMessage("(__  _)                           ░                                      (__  _)");
	client->recieveMessage("( _ __)           ▄▄▄█████▓ ▒█████      ██▓ ██▀███  ▄████▄               ( _ __)");
	client->recieveMessage("(__  _)           ▓  ██▒ ▓▒▒██▒  ██▒   ▓██▒▓██ ▒ ██▒██▀ ▀█               (_ ___)");
	client->recieveMessage("(__  _)           ▒ ▓██░ ▒░▒██░  ██▒   ▒██▒▓██ ░▄█ ▒▓█    ▄              (__  _)");
	client->recieveMessage("(_ ___)           ░ ▓██▓ ░ ▒██   ██░   ░██░▒██▀▀█▄ ▒▓▓▄ ▄██▒             (_ ___)");
	client->recieveMessage("(__  _)             ▒██▒ ░ ░ ████▓▒░   ░██░░██▓ ▒██▒ ▓███▀ ░             (__  _)");
	client->recieveMessage("( _ __)             ▒ ░░   ░ ▒░▒░▒░    ░▓  ░ ▒▓ ░▒▓░ ░▒ ▒  ░             ( _ __)");
	client->recieveMessage("(__  _)               ░      ░ ▒ ▒░     ▒ ░  ░▒ ░ ▒░ ░  ▒                (_ ___)");
	client->recieveMessage("(_ ___)             ░      ░ ░ ░ ▒      ▒ ░  ░░   ░░                     (__  _)");
	client->recieveMessage("(__  _)                        ░ ░      ░     ░    ░ ░                   (_ ___)");
	client->recieveMessage("(_ ___)                                            ░                     (__  _)");
	client->recieveMessage("(_ ___)-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.--(_ ___)");
	client->recieveMessage("`-._.-'                                                                  `-._.-'");
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