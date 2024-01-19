/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:22:50 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 15:49:53 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

std::vector<std::string> Part::commaSeperator(std::string arg)
{
	std::vector<std::string> ret;
	size_t pos = 0;
	while ((pos = arg.find(",")) != std::string::npos)
	{
		ret.push_back(arg.substr(0, pos));
		arg.erase(0, pos + 1);
	}
	ret.push_back(arg.substr(0, pos));
	return (ret);
}

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