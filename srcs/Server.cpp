/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:23:58 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/09 14:28:15 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server( const std::string & port, const std::string & pass )
{
	// std::cout << "Server constructor called." << std::endl;
	_port = port;
	_pass = pass;
	_run = true;
}

Server::~Server( void )
{
	// std::cout << "Server deconstructure called." << std::endl;
}

void Server::start( void )
{
	// สร้างซ็อกเก็ต TCP
	_server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (_server_fd < 0) {
		std::cerr << "Error creating socket" << std::endl;
		exit(1);
	}

	// ตั้งค่าตัวเลือกซ็อกเก็ต
	int optval = 1;
	setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	// ผูกซ็อกเก็ตกับที่อยู่
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(_port));
	addr.sin_addr.s_addr = INADDR_ANY;

	std::cout << "------------------------------------" << std::endl; //DEBUG
	std::cout << "starting server\n"; //DEBUG
	std::cout << "Port : " << _port << std::endl; //DEBUG
	std::cout << "Pass : " << _pass << std::endl; //DEBUG

	if (bind(_server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cerr << "Error binding socket" << std::endl;
		exit(1);
	}

	listen(_server_fd, 2);
	// next step is polling
	server_loop();
}

void Server::server_loop()
{
	std::vector<pollfd> fds;

	pollfd server_poll_fd;
	server_poll_fd.fd = _server_fd;
	server_poll_fd.events = POLLIN;

	fds.push_back(server_poll_fd);
	std::cout << "socket fd is " << fds[0].fd << "\n";
	std::cout << "------------------------------------" << std::endl; //DEBUG

	while (_run)
	{
		int events = poll(&fds[0], fds.size(), -1);

		if (events < 0)
		{
			std::cerr << "Error in poll: " << strerror(errno) << std::endl;
			break;
		}
		else if (events == 0)
		{
			std::cout << "No events to process.\n";
			continue;
		}

		for (std::vector<pollfd>::iterator it = fds.begin(); it != fds.end(); it++)
		{
			if (it->revents & POLLIN)
			{
				if (it->fd == _server_fd) 
					create_connection(fds);
				else
					receive_message(fds, it);
				break;
			}
			else if (it->revents & POLLOUT)
				std::cout << "[POLLOUT!]\n";
			else if (it->revents & POLLERR)
				std::cout << "[POLLERR!]\n";
			else if (it->revents & POLLHUP)
				std::cout << "[POLLHUP!]\n";
			else if (it->revents & POLLNVAL)
				std::cout<< "[POLLNVAL!]\n";
		}
	}

	for (int i = 0; i < fds.size(); i++)
	{
		close(fds[i].fd);
	}
}

void Server::create_connection( std::vector<pollfd> &fds )
{
	pollfd client_poll_fd;

	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	int client_fd = accept(_server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

	client_poll_fd.fd = client_fd;
	Client client(client_fd);

	if (client_fd < 0)
	{
		std::cerr << "Error accepting connection" << std::endl;
		exit(1);
	}
	fds.push_back(client_poll_fd);
	_clients.insert(std::pair<int, Client>(client_fd, client));
	std::cout << "Connected from : " << client_fd << std::endl;	
}

void Server::receive_message( std::vector<pollfd> &fds , std::vector<pollfd>::iterator it)
{
	char buffer[1024];
	int nread = recv(it->fd, buffer, sizeof(buffer), 0);
	
	/* Parser (cut after \n character) */
	std::string text(buffer);
	int found = text.find("\n");
	if (found != std::string::npos)
		text = text.substr(0, found);
	
	/* check information */
	std::cout << "receive [" << it->fd << "]: " << text << std::endl;
	if (text == "stop")
		_run = false;
	else if (text == "exit")
	{
		close(it->fd);
		fds.erase(it);
	}
	else if (text == "status")
	{
		std::cout << "[server]: [" << fds.size() - 1 << "] online users.\n"; 
	}

	if (nread < 0)
	{
		std::cerr << "Error receiving data" << std::endl;
		exit(1);
	}
	memset(buffer, 0, sizeof(buffer));
}
