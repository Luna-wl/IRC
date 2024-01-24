/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Notice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:20:56 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 22:35:04 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Notice::Notice(Server * srv) : Command(srv) {}
Notice::~Notice() {}

void Notice::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	else if ( args.size() < 3 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return;
	}

	std::vector<std::string> targets = commaSeperator(args[1]);
	std::string message;
	for (std::vector<std::string>::iterator it = args.begin() + 2; it != args.end() - 1; it++)
		message += *it + " ";
	message += *(args.end() - 1);

	for (std::vector<std::string>::iterator it=targets.begin(); it!=targets.end(); it++)
	{
		std::string target = *it;
		if ( target.at(0) == '#') { // send message to channel
			target = target.substr(1, target.size() - 1);
			Channel * channel = client->getChannel(target);
			if (channel)
				channel->sendMessage(client, RPL_CHANAWAY(client->source(), args[0], "#" + channel->getName(), message));
		}
		else { // send message to user
			Client * target_client = _srv->getClient(target);
			if (target_client)
				target_client->recieveMessage(RPL_AWAY(client->source(), args[0], client->getNickname(), message));
		}	
	}
}