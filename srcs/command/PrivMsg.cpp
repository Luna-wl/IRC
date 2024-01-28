/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrivMsg.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 02:27:35 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/18 02:29:31 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

PrivMsg::PrivMsg(Server * srv) : Command(srv) {}
PrivMsg::~PrivMsg() {}

void PrivMsg::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	else if ( args.size() < 3 ) {
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return;
	}

	std::vector<std::string> targets = commaSeperator(args[1]);
	std::string message = args[2];

	for (std::vector<std::string>::iterator it=targets.begin(); it!=targets.end(); it++)
	{
		std::string target = *it;
		if ( target.at(0) == '#') { // send message to channel
			target = target.erase(0, 1);
			Channel * channel = _srv->getChannel(target);
			if (!channel)
				client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
			else if (!client->getChannel(target))
				client->receiveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
			else
				channel->sendMessage(client, RPL_CHANAWAY(client->source(), args[0], "#" + channel->getName(), message));
		}
		else { // send message to user
			Client * target_client = _srv->getClient(target);
			if (target_client)
				target_client->receiveMessage(RPL_AWAY(client->source(), args[0], client->getNickname(), message));
			else
				client->receiveMessage(ERR_NOSUCHNICK(_srv->getName(), client->getNickname(), target));
		}
	}
}