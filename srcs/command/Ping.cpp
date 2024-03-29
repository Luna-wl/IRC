/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ping.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:29 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/29 15:49:24 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Ping::Ping(Server * srv) : Command(srv) {}
Ping::~Ping() {}

void Ping::execute(Client * client, std::vector<std::string> & args) {
	if (args.size() > 3)
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	else if (args.size() < 2)
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	else
		client->receiveMessage(RPL_PONG(client->source(), args[1]));
}