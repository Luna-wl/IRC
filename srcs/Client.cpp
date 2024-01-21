/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:53:39 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 17:31:52 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client( const int &client_fd, std::string hostname ) : _op(false)
{
    _client_fd = client_fd;
    _hostname = hostname;
    _nickname = "*";
}

Client::~Client()
{
    
}

std::string Client::source()
{
    return _nickname + "!" + _username + "@" + _hostname;
}

void Client::receive_message(std::string str)
{
    // std::cout << getNickname() << std::endl;
    // const char *buffer = str.c_str();
    // int nread = str.size();
    // std::string name = "[" + _nickname + "] : ";
    // int nsend = nread + name.size();
    // char send_buffer[nsend + 1];

    // memcpy(send_buffer, name.c_str(), name.size());
    // memcpy(send_buffer + name.size(), buffer, nread);
    // send_buffer[nsend] = '\0';
    // send(_client_fd, send_buffer, nsend, 0);
    str = str + "\n";
    send(_client_fd, str.c_str(), str.size(), 0);
}

void Client::send_error(std::string str)
{
    std::string err_str = "Error : " + str;
    receive_message(err_str);
}

void Client::send_debug(std::string str)
{
    std::string err_str = "Debug : " + str;
    receive_message(err_str);
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