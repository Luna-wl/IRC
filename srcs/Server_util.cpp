/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_util.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:43:27 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 16:37:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void Server::createConnection()
{
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_fd = accept(_server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
	if (client_fd < 0) {
		std::cerr << RED << "Error accepting connection" << DEFAULT << std::endl;
		return;
	}

	char client_ip[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &(client_addr.sin_addr), client_ip, INET_ADDRSTRLEN); // convert ip to string (human readable)

	struct sockaddr_in client_info;
	client_info.sin_family = AF_INET;
	client_info.sin_addr.s_addr = inet_addr(client_ip);
	struct hostent *host_info = gethostbyaddr((const void *)&client_info.sin_addr, sizeof(client_info.sin_addr), AF_INET);

	std::string hostname;
	if (host_info)
		hostname = host_info->h_name;
	else
		hostname = client_ip;

	std::cout << GREEN << "Connected from : " << client_fd << std::endl;
	std::cout << "hostname  : " << hostname << std::endl;
	std::cout << "client ip : " << client_ip << DEFAULT << "\n";
	addPollfd(client_fd);
	addClient(client_fd, hostname);
}

void Server::addClient(int client_fd, std::string hostname)
{
	_clients[client_fd] = new Client(client_fd, hostname);
	welcomeMessage(_clients[client_fd]);
}

void Server::addPollfd(int fd)
{
	pollfd poll_fd;
	poll_fd.fd = fd;
	poll_fd.events = POLLIN;
	_fds.push_back(poll_fd);
}

void Server::recieveMessage(int fd)
{
	Client * client = _clients.at(fd);
	char buffer[512];

	recv(fd, buffer, sizeof(buffer), 0);
	std::string text(buffer);
	bzero(buffer, sizeof(buffer));
	unsigned long found = text.find_last_not_of(" \n\r\t\f\v");
	if (found != std::string::npos)
		text = text.substr(0, found + 1);
	std::cout << "receive [" << client->getFd() << "]: " << text << std::endl;
	_parser->analyze(client, text);
}

std::string Server::time(int format)
{
	std::time_t current_time = std::time(0);
	std::tm* time_info = std::localtime(&current_time);

	char buffer[80];
	if (format == 1)
		std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", time_info);
	else if (format == 2)
		std::strftime(buffer, sizeof(buffer), "%A %B %e %Y -- %H:%M %z", time_info);
	else
	{
		std::stringstream ss;
		ss << current_time;
		return ss.str();
	}

	return std::string(buffer);
}

void Server::clientDisconnect(int fd)
{
	Client * client = _clients[fd];
	std::map<std::string, Channel *> channels = client->getAllChannel();
	for (std::map<std::string, Channel *>::iterator ch_it = channels.begin(); ch_it != channels.end(); ch_it++)
	{
		client->leave(ch_it->second);
	}
	close(fd);
	delete _clients[fd];
	_clients.erase(fd);
	for (std::vector<pollfd>::iterator it = _fds.begin(); it != _fds.end(); it++)
	{
		if (it->fd == fd)
		{
			_fds.erase(it);
			break;
		}
	}
	std::cout << YELLOW << "Disconnect from user [" << fd << "]\n" << DEFAULT;
}

bool isStrDigit(std::string str)
{
	int size = str.size();
	const char * cstr = str.c_str();
	for (int i = 0; i < size; i++)
	{
		if (!isdigit(cstr[i]))
			return false;
	}
	return true;
}

bool isStrPrint(std::string str)
{
	int size = str.size();
	const char * cstr = str.c_str();
	for (int i = 0; i < size; i++)
	{
		if (!isprint(cstr[i]) || cstr[i] == ' ')
			return false;
	}
	return true;
}

std::string intToString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}