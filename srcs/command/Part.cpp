/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:50 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Part::Part(Server * srv) : Command(srv) {}
Part::~Part() {}

void Part::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() == 1 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	} else {
		std::vector<std::string> channels = commaSeperator(args[1]);

		std::vector<std::string>::iterator ch_it = channels.begin();
		while (ch_it != channels.end())
		{
			std::string channel_name = *ch_it;
			
			if (channel_name[0] != '#' || channel_name.size() == 1) {
				client->recieveMessage(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), channel_name));
				ch_it++;
				continue;
			}
			channel_name.erase(0, 1);
			
			Channel * channel = client->getChannel(channel_name);
			if (!channel) {
				client->recieveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
			} else {
				client->leave(channel);
			}
			ch_it++;
		}
	}
}