/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:20:56 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 17:30:38 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Notice::Notice(Server * srv) : Command(srv) {}
Notice::~Notice() {}

void Notice::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	else if ( args.size() < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return;
	}

	std::string target = args[1];
	std::string message;
	for (std::vector<std::string>::iterator it = args.begin() + 2; it != args.end() - 1; it++)
		message += *it + " ";
	message += *(args.end() - 1);

	if ( target.at(0) == '#') { // send message to channel
		target = target.substr(1, target.size() - 1);
		Channel * channel = client->getChannel(target);
		if (channel)
			channel->send_message(client, RPL_CHANAWAY(client->source(), args[0], "#" + channel->getName(), message));
	}
	else { // send message to user
		Client * target_client = _srv->get_client(target);
		if (target_client)
			target_client->receive_message(RPL_AWAY(client->source(), args[0], client->getNickname(), message));
	}	
}