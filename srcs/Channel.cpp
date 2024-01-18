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

Channel::Channel(std::string name, std::string key) : _i(false), _t(false), _k(false), _o(false), _l(false)
{
	_name = name;
	if (!key.empty()) {
		_key = key;
		_k = true;
	}
	// std::cout << "Debug : channel created" << std::endl;
}

Channel::~Channel() {}

void Channel::addClient(Client * client)
{
	_members.push_back(client);
}

void Channel::send_message(Client * client, std::string message) {
	for (std::vector<Client *>::iterator it = _members.begin(); it != _members.end(); it++) {
		if ((*it) == client)
			continue;
		(*it)->receive_message(message);
	}
}

std::string Channel::getName()
{
	return _name;
}

std::string Channel::getKey()
{
	return _key;
}

bool Channel::isFull()
{
	return _members.size() == _userLimit ? true : false;
}

bool Channel::isInviteMode()
{
	return _i;
}

bool Channel::isKeyMode()
{
	return _k;
}

bool Channel::isLimitMode()
{
	return _l;
}

bool Channel::isOperMode()
{
	return _o;
}

bool Channel::isTopicMode()
{
	return _t;
}