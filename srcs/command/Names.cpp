/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:42:31 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/19 23:18:08 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Names::Names(Server * srv) : Command(srv) {}
Names::~Names() {}

std::string getSymbol(Channel * channel)
{
	std::string symbol;
	if (channel->isKeyMode())
		symbol = "*";
	else if (channel->isOperMode())
		symbol = "@";
	else
		symbol = "=";
	return symbol;
}

void Names::execute(Client * client, std::vector<std::string> & args)
{
 	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), args[0]));
	}
	else if ( args.size() == 1 ) {
		std::string nick;
		std::map<const int, Client *> member = _srv->getClient();
		for (std::map<const int, Client *>::iterator it = member.begin(); it != member.end(); it++)
			nick += it->second->getNickname() + " ";
		client->receive_message(RPL_NAMREPLY(client->source(), args[0], "", "", nick));
		client->receive_message(RPL_ENDOFNAMES(client->source(), args[0], ""));
	}
	else {
		std::vector<std::string> channels = commaSeperator(args[1]);
		for(std::vector<std::string>::iterator it = channels.begin();it != channels.end(); it++)
		{
			std::string channel_name = *it;

			Channel * channel;
			if (!_srv->isChanExist(channel_name))
				continue;

			channel = _srv->getChannel(channel_name);
			std::string symbol = getSymbol(channel);

			std::map<std::string, Client *> member = channel->getMember();
			std::string nick;
			for (std::map<std::string, Client *>::iterator it = member.begin(); it != member.end(); it++)
				nick += it->first + " "; // not yet (add prefix @op_user)
			client->receive_message(RPL_NAMREPLY(client->source(), args[0], symbol, channel_name, nick));
			client->receive_message(RPL_ENDOFNAMES(client->source(), args[0], channel_name));
		}
	}
}