/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:58:49 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 17:47:26 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Join::Join(Server * srv) : Command(srv) {}
Join::~Join() {}

void Join::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), args[0]));
	}
	else if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	}
	else if ( client->getChannelSize() == CHANLIMIT ) {
		client->receive_message(ERR_TOOMANYCHANNELS(_srv->getName(), args[0], args[1]));
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
			
			Channel * channel;
			if (!_srv->isChanExist(channel_name)) {
				channel = new Channel(channel_name, channel_key);
				_srv->addChannel(channel);
			} else {
				channel = _srv->getChannel(channel_name);
			}

			if (channel->isKeyMode() && channel_key != channel->getKey()) {
				client->receive_message(ERR_BADCHANNELKEY(_srv->getName(), args[0], channel->getName()));
			} else if (channel->isLimitMode() && channel->isFull()) {
				client->receive_message(ERR_CHANNELISFULL(_srv->getName(), args[0], channel->getName()));
			} else if (channel->isInviteMode()) {
				client->receive_message(ERR_INVITEONLYCHAN(_srv->getName(), args[0], channel->getName()));
			} 
			/* use after setting Client OPER finish */
			// else if (channel->isOperMode() && <client must be oper>) {
				
			// } 
			else {
				client->join(channel);
			}
			if (key_it != keys.end())
				key_it++;
			ch_it++;
		}
	}
}