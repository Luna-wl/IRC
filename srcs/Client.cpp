/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:53:39 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/11 23:14:40 by csantivimol      ###   ########.fr       */
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

int Client::getFd()
{
    return _client_fd;
}