/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:55 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 03:20:50 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

Channel::Channel(Server * srv, std::string name, std::string key) : _i(false), _t(false), _k(false), _l(false)
{
	_srv = srv;
	_name = name;
	_userLimit = 3;
	if (!key.empty()) {
		_key = key;
		_k = true;
	}
	// std::cout << "Debug : channel created" << std::endl;
}

Channel::~Channel() {}

void Channel::addMember(Client * member)
{
	send_message(member, RPL_JOINCHAN(member->source(), getName()));
	_members[member->getNickname()] = member;
}

void Channel::removeClient(Client * member)
{
	if (!_members.count(member->getNickname()))
		return;
	_members.erase(member->getNickname());
	if (_members.size() == 0) {
		_srv->removeChannel(_name);
		return ;
	}
	send_message(member, RPL_LEAVECHAN(member->source(), getName()));
}

void Channel::addChanOp(std::string nick)
{
	_opMembers[nick] = true;
}

bool Channel::isChanOp(std::string nick)
{
	return _opMembers.count(nick) ? true : false;
}

void Channel::send_message(Client * member, std::string message) {
	for (std::map<std::string, Client *>::iterator it = _members.begin(); it != _members.end(); it++) {
		if (it->second == member)
			continue;
		it->second->receive_message(message);
	}
}

std::map<std::string, Channel *> Client::getAllChannel()
{
	return _channels;
}

std::map<std::string, Client *> Channel::getMember()
{
	return _members;
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

bool Channel::isTopicMode()
{
	return _t;
}