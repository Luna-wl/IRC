/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:55 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/18 04:08:42 by tkraikua         ###   ########.fr       */
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
		(*it)->receive_message(RPL_AWAY(client->getNickname(), message));
	}
}

std::string Channel::getName()
{
	return _name;
}