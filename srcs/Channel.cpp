/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:55 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 00:56:23 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(std::string name, std::string key)
{
	_name = name;
	if (!_key.empty())
		_key = key;
	// std::cout << "Debug : channel created" << std::endl;
}

Channel::~Channel() {}

void Channel::addClient(Client * client)
{
	_clients.push_back(client);
}

void Channel::send_message(Client * client, std::string message) {
	for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); it++) {
		if ((*it) == client)
			continue;
		(*it)->receive_message(message);
	}
}

std::string Channel::getName()
{
	return _name;
}