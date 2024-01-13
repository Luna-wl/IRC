/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server_util.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:43:27 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/14 01:27:36 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

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
	add_pollfd(client_fd);
	add_client(client_fd);
}

void Server::add_client(int client_fd)
{
	_clients[client_fd] = new Client(client_fd);
	// Client client(client_fd);
	// _clients.insert(std::pair<const int, Client>(client_fd, client));
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
	char buffer[1024];
	
	recv(fd, buffer, sizeof(buffer), 0);
	std::string text(buffer);
	int found = text.find("\n");
	if (found != std::string::npos)
		text = text.substr(0, found);

	_parser->analyze(client, text);
}

// void Server::receive_message(std::vector<pollfd>::iterator it)
// {
// 	char buffer[1024];
// 	int nread = recv(it->fd, buffer, sizeof(buffer), 0);

// 	if (nread < 0)
// 	{
// 		std::cerr << RED << "[server]: Error receiving data." << std::endl;
// 		close(it->fd);
// 		_fds.erase(it);
// 	}

// 	/* Parser (cut after \n character) */
// 	std::string text(buffer);
// 	int found = text.find("\n");
// 	if (found != std::string::npos)
// 		text = text.substr(0, found);

// 	/* check information */
// 	if (text[0] == '>') // try send message to another 
// 	{
// 		std::string name = "[" + std::to_string(it->fd) + "] : ";
// 		int nsend = nread + name.size();
// 		char send_buffer[nsend + 1];

// 		memcpy(send_buffer, name.c_str(), name.size());
// 		memcpy(send_buffer + name.size(), buffer, nread);\
// 		send_buffer[nsend] = '\0';
// 		for (std::vector<pollfd>::iterator itt = _fds.begin(); itt != _fds.end(); itt++)
// 		{
// 			if (itt->fd == _server_fd || itt == it)
// 				continue;
// 			send(itt->fd, send_buffer, nsend, 0);
// 		}
// 	}
// 	else if (text == "stop")
// 	{
// 		_run = false;
// 		std::cout << "[server]: shutting down . . .\n";
// 	}
// 	else if (text == "status")
// 		std::cout << "[server]: [" << _fds.size() - 1 << "] online users.\n"; 
// 	else
// 		std::cout << "receive [" << it->fd << "]: " << text << std::endl;
// 	memset(buffer, 0, sizeof(buffer));
// }