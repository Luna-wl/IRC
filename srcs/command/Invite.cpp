/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:17 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Invite::Invite(Server * srv) : Command(srv) {}
Invite::~Invite() {}

void Invite::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() < 3 ) {
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( args.size() > 3 ) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else if ( args[2][0] != '#' || args[2].size() == 1 ) {
		client->receiveMessage(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), args[1]));
	}
  else {
		std::string user_name = args[1];
		Client * user = _srv->getClient(user_name);
		
		std::string channel_name = args[2];
		channel_name.erase(0, 1);
		Channel * channel = _srv->getChannel(channel_name);

		if ( !user ) {
			client->receiveMessage(ERR_NOSUCHNICK(_srv->getName(), client->getNickname(), user_name));
		}
		else if ( !channel ) {
			client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
		}
		else if ( !client->getChannel(channel_name) ) {
			client->receiveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
		}
		else if ( channel->isInviteMode() && !channel->isChanOp(client->getNickname()) ) {
			client->receiveMessage(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), "#" + channel_name));
		}
		else if ( user->getChannel(channel_name) ) {
			client->receiveMessage(ERR_USERONCHANNEL(_srv->getName(), client->getNickname(), user_name, "#" + channel_name));
		}
    else if (channel->isLimitMode() && channel->isFull()) {
			client->receiveMessage(ERR_CHANNELISFULL(_srv->getName(), client->getNickname(), channel->getName()));
		}
    else {
			client->receiveMessage(RPL_INVITING(_srv->getName(), args[0], user_name, channel_name));
			user->join(channel);
		}
	}
}