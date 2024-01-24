/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:23:58 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 21:02:43 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Server.hpp"

bool Server::_run = true;

Server::Server( const std::string & port, const std::string & pass ) {
	// std::cout << "Server constructor called." << std::endl;
	_name = "Rudolph";
	_port = port;
	_pass = pass;
	_run = true;
	_parser = new Parser(this);
}

Server::~Server( void ) {
	// std::cout << "Server deconstructure called." << std::endl;
	delete _parser;
	for (std::map<const int, Client *>::iterator it=_clients.begin(); it!=_clients.end(); it++)
	{
		delete it->second;
	}
	for (std::map<std::string, Channel *>::iterator it=_channels.begin(); it!=_channels.end(); it++)
	{
		delete it->second;
	}
	for (unsigned long i = 0; i < _fds.size(); i++)
	{
		close(_fds[i].fd);
	}
}

int Server::start( void ) {
	_server_fd = socket(AF_INET, SOCK_STREAM, 0); // create a TCP socket
	if (_server_fd < 0)
	{
		std::cerr << RED << "Error creating socket" << DEFAULT << std::endl;
		return(1);
	}

	if (fcntl(_server_fd, F_SETFL, O_NONBLOCK))
	{
		std::cerr << RED << "Error non blocking" << DEFAULT << std::endl;
		return (1);
	}

	int optval = 1;
	if (setsockopt(_server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		std::cerr << RED << "Error set socket" << DEFAULT << std::endl;
		return(1);
	}

	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(_port));
	addr.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to the specified address and port
	if (bind(_server_fd, (struct sockaddr *)&addr, sizeof(addr)) != 0) {
		std::cerr << RED << "Error binding socket" << std::endl;
		return(1);
	}
	listen(_server_fd, 5); // backlog = 5
	std::cout << "Server starting . . .\n";
	return (0);
}

void Server::serverLoop() {
	addPollfd(_server_fd);

	while (_run)
	{
		int events = poll(&_fds[0], _fds.size(), -1);
		if (!_run)
			break;
		if (events < 0)
		{
			std::cerr << RED << "Error in poll" << DEFAULT << std::endl;
			break;
		}
		else if (events == 0)
		{
			std::cout << "No events to process." << std::endl;
			continue;
		}

		for (std::vector<pollfd>::iterator it = _fds.begin(); it != _fds.end(); it++)
		{
			if (it->revents & POLLHUP)
			{
				clientDisconnect(it->fd);
				break;
			}
			else if (it->revents & POLLIN)
			{
				if (it->fd == _server_fd)
					createConnection();
				else
					recieveMessage(it->fd);
				break;
			}
			else if (it->revents & POLLOUT)
				std::cout << YELLOW << "[POLLOUT!]" << DEFAULT << std::endl;
			else if (it->revents & POLLERR)
				std::cout << YELLOW << "[POLLERR!]" << DEFAULT << std::endl;
			else if (it->revents & POLLNVAL)
				std::cout << YELLOW<< "[POLLNVAL!]" << DEFAULT << std::endl;
		}
	}
}

void Server::set_state(bool state) {
	Server::_run = state;
}

std::string Server::getName() {
	return _name;
}

std::string Server::getPass() {
	return _pass;
}

std::map<const int, Client *> 	&Server::getAllClient() {
	return _clients;
}

Client * Server::getClient(std::string client_nickname) {
	Client * client = NULL;
	for (std::map<const int, Client *>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if (client_nickname == it->second->getNickname())
			client = it->second;
	}
	return client;
}

void Server::addChannel(Channel * channel) {
	_channels[channel->getName()] = channel;
}

void Server::removeChannel(std::string channel_name)
{
	delete _channels[channel_name];
	_channels.erase(channel_name);
}

Channel * Server::getChannel(std::string channel_name) {
	return _channels.count(channel_name) ? _channels[channel_name] : NULL;
}

bool Server::isChanExist(std::string channel_name) {
	return _channels.count(channel_name) ? true : false;
}

std::map<std::string, Channel*>& Server::getChannels() {
	return _channels;
}

std::string Server::getPort() {
	return _port;
}

int Server::getChannelNum() {
	return _channels.size();
}

int Server::getClientNum() {
	return _clients.size();
}