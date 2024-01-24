/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:55 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 23:16:30 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Channel.hpp"

Channel::Channel(Server * srv, std::string name, std::string key) : _i(false), _t(false), _k(false), _l(false)
{
	_srv = srv;
	_name = name;
	_userLimit = 3;
	if (!key.empty()) {
		_key = key;
		_k = true;
	}
}

Channel::~Channel() {}

void Channel::addMember(Client * member)
{
	sendMessage(member, RPL_JOINCHAN(member->source(), getName()));
	_members[member->getNickname()] = member;
}

void Channel::removeClient(Client * member)
{
	if (!_members.count(member->getNickname()))
		return;
	_members.erase(member->getNickname());
	removeChanOp(member->getNickname());
	if (_members.size() == 0) {
		_srv->removeChannel(_name);
		return ;
	}
	sendMessage(member, RPL_LEAVECHAN(member->source(), getName()));
}

void Channel::addChanOp(std::string nick)
{
	_opMembers[nick] = true;
}

void Channel::removeChanOp(std::string nick)
{
	if (_opMembers.count(nick))
		_opMembers.erase(nick);
}

bool Channel::isChanOp(std::string nick)
{
	return _opMembers.count(nick) ? true : false;
}

void Channel::sendMessage(Client * member, std::string message) {
	for (std::map<std::string, Client *>::iterator it = _members.begin(); it != _members.end(); it++) {
		if (it->second == member)
			continue;
		it->second->recieveMessage(message);
	}
}

int Channel::getClietNum() {
	return _members.size();
}

std::string Channel::getTopic() {
	return _topic;
}

void Channel::_setTopic(std::string topic) {
	_topic = topic;
}

std::map<std::string, Channel *> Client::getAllChannel()
{
	return _channels;
}

std::map<std::string, Client *> Channel::getMember()
{
	return _members;
}

std::map<std::string, bool> Channel::getOpMember()
{
	return _opMembers;
}

std::string Channel::getName()
{
	return _name;
}

std::string Channel::getKey()
{
	return _key;
}

int	Channel::getLimit()
{
	return _userLimit;
}

bool Channel::isFull()
{
	return _members.size() >= _userLimit ? true : false;
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

void Channel::setInviteMode(bool state)
{
	_i = state;
}

void Channel::setTopicMode(bool state)
{
	_t = state;
}

void Channel::setKeyMode(bool state, std::string key)
{
	_k = state;
	if (!key.empty())
		_key = key;
}

void Channel::setLimitMode(bool state, int limit)
{
	_l = state;
	_userLimit = limit;
}