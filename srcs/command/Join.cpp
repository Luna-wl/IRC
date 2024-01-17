/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:58:49 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/18 01:44:26 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Join::Join(Server * srv) : Command(srv) {}
Join::~Join() {}

void Join::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED);
	}
	else if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(args[0]));
	}
	else if ( client->getChannelSize() == CHANLIMIT ) {
		client->receive_message(ERR_TOOMANYCHANNELS(args[1]));
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