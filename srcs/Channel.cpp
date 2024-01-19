/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:55 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 15:36:14 by tkraikua         ###   ########.fr       */
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

void Channel::addClient(Client * member)
{
	_members[member->getNickname()] = member;
}

void Channel::removeClient(Client * member)
{
	if (_members.count(member->getNickname()))
		_members.erase(member->getNickname());
}

void Channel::send_message(Client * member, std::string message) {
	for (std::map<std::string, Client *>::iterator it = _members.begin(); it != _members.end(); it++) {
		if (it->second == member)
			continue;
		it->second->receive_message(message);
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