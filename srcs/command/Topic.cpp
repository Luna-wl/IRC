/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:32:51 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Topic::Topic(Server * srv) : Command(srv) {}

Topic::~Topic() {}

void Topic::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	int num = args.size();
	if (num == 1)
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), "TOPIC"));
	else if (num == 2) {
		if (args[1][0] == '#') {
			// TOPIC #test	Checking the topic for "#test"
			std::string channel_name = args[1];
			Channel * channel = _srv->getChannel(channel_name.erase(0, 1));
			if (!channel)
				client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			else if (!client->getChannel(channel_name))
				client->receiveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			else if (channel->getTopic() != "")
				client->receiveMessage(RPL_TOPIC(_srv->getName(), args[1], _srv->getChannel(channel_name)->getTopic()));
			else
				client->receiveMessage(RPL_NOTOPIC(_srv->getName(), args[1]));
		}
		else
			client->receiveMessage(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else if (num == 3) {
			// TOPIC #test : 	Clearing the topic on "#test"
			if (args[1][0] == '#') {
			// TOPIC #test :New topic 	Setting the topic on "#test" to "New topic".
				std::string channel_name = args[1];
				Channel * channel = _srv->getChannel(channel_name.erase(0, 1));
				if (!channel)
					client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
				else if (!client->getChannel(channel_name))
					client->receiveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), args[1]));
				else if (channel->isTopicMode() && !channel->isChanOp(client->getNickname()))
					client->receiveMessage(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), args[1]));
				else
					_srv->getChannel(channel_name)->_setTopic(&args[2][0]);
			}
			else
				client->receiveMessage(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), "TOPIC"));
}
