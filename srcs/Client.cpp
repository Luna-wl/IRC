/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:53:39 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/19 22:34:36 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Client.hpp"

Client::Client( const int &client_fd, std::string hostname )
{
    _client_fd = client_fd;
    _hostname = hostname;
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

void Client::join(Channel * channel)
{
    _channels[channel->getName()] = channel;
    channel->addClient(this);
    // std::cout << "Debug : set channel in client" << std::endl;
}

Channel * Client::getChannel(std::string channel_name)
{
    return _channels.count(channel_name) ? _channels[channel_name] : NULL;
}

int Client::getChannelSize()
{
    return _channels.size();
}