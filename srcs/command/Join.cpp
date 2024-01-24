/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:58:49 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Join::Join(Server * srv) : Command(srv) {}
Join::~Join() {}

void Join::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() == 1 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( client->getChannelSize() == CHANLIMIT ) {
		client->recieveMessage(ERR_TOOMANYCHANNELS(_srv->getName(), client->getNickname(), args[1]));
	}
	else {
		std::vector<std::string> channels = commaSeperator(args[1]);
		std::vector<std::string> keys;
		if (args.size() > 2)
			keys = commaSeperator(args[2]);

		std::vector<std::string>::iterator ch_it = channels.begin();
		std::vector<std::string>::iterator key_it = keys.begin();
		while (ch_it != channels.end())
		{
			std::string channel_name = *ch_it;
			std::string channel_key = key_it != keys.end() ? *key_it : "";

			if (channel_name[0] != '#' || channel_name.size() == 1) {
				client->recieveMessage(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), channel_name));
				ch_it++;
				continue;
			}
			channel_name.erase(0, 1);
			
			Channel * channel;
			if (!_srv->isChanExist(channel_name)) {
				channel = new Channel(_srv, channel_name, channel_key);
				_srv->addChannel(channel);
				channel->addChanOp(client->getNickname());
			} else {
				channel = _srv->getChannel(channel_name);
			}

			if (channel->isKeyMode() && channel_key != channel->getKey()) {
				client->recieveMessage(ERR_BADCHANNELKEY(_srv->getName(), client->getNickname(), channel->getName()));
			} else if (channel->isLimitMode() && channel->isFull()) {
				client->recieveMessage(ERR_CHANNELISFULL(_srv->getName(), client->getNickname(), channel->getName()));
			} else if (channel->isInviteMode()) {
				client->recieveMessage(ERR_INVITEONLYCHAN(_srv->getName(), client->getNickname(), channel->getName()));
			} else {
				if (!channel->getTopic().empty())
					client->recieveMessage(RPL_TOPIC(_srv->getName(), "#" + channel_name, channel->getTopic()));
				client->join(channel);
			}
			if (key_it != keys.end())
				key_it++;
			ch_it++;
		}
	}
}