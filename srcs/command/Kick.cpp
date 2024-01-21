/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:03:35 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/21 19:40:08 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Kick::Kick(Server * srv) : Command(srv) {}
Kick::~Kick() {}

void Kick::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	} else if ( args.size() < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	} else if ( args[1][0] != '#' || args[1].size() == 1 ) {
		client->receive_message(ERR_BADCHANMASK(_srv->getName(), client->getNickname(), args[1]));
	} else {
		std::string channel_name = args[1];
		channel_name.erase(0, 1);
		Channel * channel = _srv->getChannel(channel_name);
		
		std::vector<std::string> users = commaSeperator(args[2]);

		for (std::vector<std::string>::iterator user_it=users.begin(); user_it!=users.end(); user_it++)
		{
			std::string user_name = *user_it;
			Client * user = _srv->get_client(user_name);
			
			if ( !channel ) {
				client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
			} else if ( !client->getChannel(channel_name) ) {
				client->receive_message(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + channel_name));
			} else if ( !user || !user->getChannel(channel_name) ) {
				client->receive_message(ERR_USERNOTINCHANNEL(_srv->getName(), client->getNickname(), user_name, "#" + channel_name));
			} else if ( !client->isOper() && !channel->isChanOp(client->getNickname()) ) {
				client->receive_message(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), "#" + channel_name));
			} else {
				user->leave(channel);
			}
		}
	}
}