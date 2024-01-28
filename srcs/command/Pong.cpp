/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pong.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:53:29 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 22:08:50 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Pong::Pong(Server * srv) : Command(srv) {}
Pong::~Pong() {}

void Pong::execute(Client * client, std::vector<std::string> & args) {
  if (args.size() > 2)
		client->receive_message(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	else if (args[1].empty())
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	else
		client->receive_message(RPL_PONG(client->source(), args[1]));
}