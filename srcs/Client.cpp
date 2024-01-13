/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:53:39 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/14 01:10:33 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client( const int &client_fd )
{
    _client_fd = client_fd;
}

Client::~Client()
{
    
}

void Client::receive_message(std::string str)
{
    std::cout << getNickname() << std::endl;
    const char *buffer = str.c_str();
    int nread = str.size();
    std::string name = "[" + _nickname + "] : ";
    int nsend = nread + name.size();
    char send_buffer[nsend + 1];

    memcpy(send_buffer, name.c_str(), name.size());
    memcpy(send_buffer + name.size(), buffer, nread);\
    send_buffer[nsend] = '\0';
    send(_client_fd, send_buffer, nsend, 0);
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
