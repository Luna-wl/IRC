/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:39:17 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 17:28:33 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Invite::Invite(Server * srv) : Command(srv) {}
Invite::~Invite() {}

void Invite::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	} else if ( args.size() < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	} else if ( args[2][0] != '#' || args[2].size() == 1 ) {
		client->receive_message(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), args[1]));
	} else {
		std::string user_name = args[1];
		Client * user = _srv->get_client(user_name);
		
		std::string channel_name = args[2];
		channel_name.erase(0, 1);
		Channel * channel = _srv->getChannel(channel_name);

		if ( !user ) {
			client->receive_message(ERR_NOSUCHNICK(_srv->getName(), client->getNickname(), user_name));
		} else if ( !channel ) {
			client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
		} else if ( !client->getChannel(channel_name) ) {
			client->receive_message(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
		} else if ( channel->isInviteMode() && !channel->isChanOp(client->getNickname()) ) {
			client->receive_message(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), "#" + channel_name));
		} else if ( user->getChannel(channel_name) ) {
			client->receive_message(ERR_USERONCHANNEL(_srv->getName(), client->getNickname(), user_name, "#" + channel_name));
		} else {
			client->receive_message(RPL_INVITING(_srv->getName(), args[0], user_name, channel_name));
			user->join(channel);
		}
	}
}