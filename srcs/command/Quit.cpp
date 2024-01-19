/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:41 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/19 23:46:43 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Quit::Quit(Server * srv) : Command(srv) {}
Quit::~Quit() {}

void Quit::execute(Client * client, std::vector<std::string> & args)
{
    // remove client from channel
    std::map<std::string, Channel *> channels = client->getAllChannel();
    for (std::map<std::string, Channel *>::iterator ch_it = channels.begin(); ch_it != channels.end(); ch_it++)
    {
        client->leave(ch_it->second);
    }
    // disconnect with server
    _srv->clientDisconnect(client->getFd());
}