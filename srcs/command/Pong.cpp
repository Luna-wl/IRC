/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:29 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 18:09:51 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Pong::Pong(Server * srv) : Command(srv) {}
Pong::~Pong() {}

void Pong::execute(Client * client, std::vector<std::string> & args)
{
    if (args[1].empty())
    {
        client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
        return ;
    }
    client->receive_message(RPL_PONG(client->source(), args[1]));
}