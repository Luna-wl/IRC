/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:32:51 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Topic::Topic(Server * srv) : Command(srv) {}

Topic::~Topic() {}

void Topic::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	int num = args.size();
	if (num < 2)
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), "TOPIC"));
	else if (num == 2) {
		if (args[1][0] == '#') {
			// TOPIC #test	Checking the topic for "#test"
			std::string channel_name = args[1];
			Channel * channel = _srv->getChannel(channel_name.erase(0, 1));
			if (!channel)
				client->recieveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			else if (!client->getChannel(channel_name))
				client->recieveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), channel_name));
			else if (channel->getTopic() != "")
				client->recieveMessage(RPL_TOPIC(_srv->getName(), args[1], _srv->getChannel(channel_name)->getTopic()));
			else
				client->recieveMessage(RPL_NOTOPIC(_srv->getName(), args[1]));
		}
		else
			client->recieveMessage(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else if (num == 3) {
			// TOPIC #test : 	Clearing the topic on "#test"
			if (args[1][0] == ':')
				_srv->getChannel(args[1])->_setTopic("");
			else if (args[1][0] == '#') {
			// TOPIC #test :New topic 	Setting the topic on "#test" to "New topic".
				std::string channel_name = args[1];
				Channel * channel = _srv->getChannel(channel_name.erase(0, 1));
				if (!channel)
					client->recieveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), channel_name));
				else if (!client->getChannel(channel_name))
					client->recieveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), channel_name));
				else if (channel->isTopicMode() && !channel->isChanOp(client->getNickname()))
					client->recieveMessage(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), channel_name));
				else
					_srv->getChannel(channel_name)->_setTopic(&args[2][0]);
			}
			else
				client->recieveMessage(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else
		client->recieveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), "TOPIC"));
}
