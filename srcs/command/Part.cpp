/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:50 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 02:06:57 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Part::Part(Server * srv) : Command(srv) {}
Part::~Part() {}

void Part::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), args[0]));
	}
	else if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	} else {
		std::vector<std::string> channels = commaSeperator(args[1]);

		std::vector<std::string>::iterator ch_it = channels.begin();
		while (ch_it != channels.end())
		{
			std::string channel_name = *ch_it;
			
			if (channel_name[0] != '#') {
				client->receive_message(ERR_BADCHANMASK(_srv->getName(), args[0], channel_name));
				ch_it++;
				continue;
			}
			channel_name.erase(0, 1);
			
			Channel * channel = client->getChannel(channel_name);
			if (!channel) {
				client->receive_message(ERR_NOTONCHANNEL(_srv->getName(), args[0], "#" + channel_name));
			} else {
				client->leave(channel);
			}
			ch_it++;
		}
	}
}