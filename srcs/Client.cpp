/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:53:39 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 19:17:04 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Client.hpp"

Client::Client( const int &client_fd, std::string hostname ) : _op(false)
{
	_client_fd = client_fd;
	_hostname = hostname;
	_nickname = "*";
	_auth = false;
}

Client::~Client() {}

std::string Client::source() {
	return _nickname + "!" + _username + "@" + _hostname;
}

void Client::receiveMessage(std::string str) {
	str = str + "\r\n";
	send(_client_fd, str.c_str(), str.size(), 0);
}

int Client::getFd()
{
	return _client_fd;
}

std::string Client::getNickname()
{
	return _nickname;
}
std::string Client::getHostname()
{
	return _hostname;
}
std::string Client::getServername()
{
	return _servername;
}
std::string Client::getFullname()
{
	return _fullname;
}
std::string Client::getUsername()
{
	return _username;
}

void Client::setNickname(std::string name)
{
	_nickname = name;
}
void Client::setHostname(std::string name)
{
	_hostname = name;
}
void Client::setServername(std::string name)
{
	_servername = name;
}
void Client::setFullname(std::string name)
{
	_fullname = name;
}
void Client::setUsername(std::string name)
{
	_username = name;
}

bool Client::isAuth()
{
	return _auth;
}

void Client::setAuth(bool state)
{
	_auth = state;
}

bool Client::isRegist()
{
	return _regist;
}

void Client::setRegist(bool state)
{
	_regist = state;
}

bool Client::isOper()
{
	return _op;
}

void Client::setOper(bool state)
{
	_op = state;
}

void Client::leave(Channel * channel)
{
	if (!_channels.count(channel->getName()))
		return ;
	_channels.erase(channel->getName());
	channel->removeClient(this);
}

void Client::join(Channel * channel)
{
	if (_channels.count(channel->getName()))
		return ;
	_channels[channel->getName()] = channel;
	channel->addMember(this);
}

Channel * Client::getChannel(std::string channel_name)
{
	return _channels.count(channel_name) ? _channels[channel_name] : NULL;
}

int Client::getChannelSize()
{
	return _channels.size();
}