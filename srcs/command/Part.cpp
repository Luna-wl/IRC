/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:50 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Part::Part(Server * srv) : Command(srv) {}
Part::~Part() {}

void Part::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() == 1 ) {
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( args.size() > 3 ) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else {
		std::vector<std::string> channels = commaSeperator(args[1]);

		std::vector<std::string>::iterator ch_it = channels.begin();
		while (ch_it != channels.end())
		{
			std::string channel_name = *ch_it;
			
			if (channel_name[0] != '#' || channel_name.size() == 1) {
				client->receiveMessage(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), channel_name));
				ch_it++;
				continue;
			}
			channel_name.erase(0, 1);
			
			Channel * channel = client->getChannel(channel_name);
			if (!channel) {
				client->receiveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
			} else {
				client->leave(channel);
			}
			ch_it++;
		}
	}
}