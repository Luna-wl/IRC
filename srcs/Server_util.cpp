/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_util.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:43:27 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/25 00:05:25 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

void Server::create_connection()
{
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int client_fd = accept(_server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
	if (client_fd < 0)
	{
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

	std::cout << "addr Port : " << client_addr.sin_port << std::endl;
	std::cout << "hostname  : " << hostname << std::endl;
	std::cout << "client ip : " << client_ip << std::endl;
	add_pollfd(client_fd);
	add_client(client_fd, hostname);
}

void Server::add_client(int client_fd, std::string hostname)
{
	_clients[client_fd] = new Client(client_fd, hostname);
	std::cout << "Connected from : " << client_fd << std::endl;
}

void Server::add_pollfd(int fd)
{
	pollfd poll_fd;
	poll_fd.fd = fd;
	poll_fd.events = POLLIN;
	_fds.push_back(poll_fd);
}

void Server::receive_message(int fd)
{
	Client * client = _clients.at(fd);
	char buffer[512];

	recv(fd, buffer, sizeof(buffer), 0);
	std::string text(buffer);
	bzero(buffer, sizeof(buffer));
	unsigned long found = text.find_last_not_of(" \n\r\t\f\v");
	if (found != std::string::npos)
		text = text.substr(0, found + 1);
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
	close(fd); // close fd
	delete _clients[fd]; // release memory
	_clients.erase(fd); // remove from _client
	for (std::vector<pollfd>::iterator it = _fds.begin(); it != _fds.end(); it++)
	{
		if (it->fd == fd)
		{
			_fds.erase(it); // remove from _fds
			break;
		}
	}
	std::cout << "[server]: Disconnect from user [" << fd << "]\n";
}