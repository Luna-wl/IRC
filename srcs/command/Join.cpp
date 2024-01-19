/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:58:49 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 22:40:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Join::Join(Server * srv) : Command(srv) {}
Join::~Join() {}

void Join::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName()));
	}
	else if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	}
	else if ( client->getChannelSize() == CHANLIMIT ) {
		client->receive_message(ERR_TOOMANYCHANNELS(_srv->getName(), args[1]));
	}
	else {
		std::string channel_name = args[1];
		std::string channel_key = args.size() > 1 ? args[1] : "";
		Channel * channel;
		if (!_srv->isChanExist(channel_name)) {
			channel = new Channel(channel_name, channel_key);
			_srv->addChannel(channel);
		} else {
			channel = _srv->getChannel(channel_name);
		}
		client->join(channel);
	}
}