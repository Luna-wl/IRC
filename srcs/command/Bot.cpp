/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:50:44 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/23 17:36:46 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Bot::Bot(Server * srv) : Command(srv) {}
Bot::~Bot() {}

std::string Bot::getName()
{
	return "RD-BOT";
}

void Bot::execute(Client * client, std::vector<std::string> & args)
{
	int size = args.size();
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return ;
	} else if ( size < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return ;
	}
	
	std::string target;
	std::string message;

	if ( args[1][0] == '#') { // user send message to "channel operator"
		target = args[1].substr(1, args[1].size() - 1);
		Channel * channel = _srv->getChannel(target);
		message = args[2];
		if (!channel)
			client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
		else if (!client->getChannel(target))
			client->receive_message(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
		else
		{
			std::map<std::string, bool> opMembers = channel->getOpMember();
			for (std::map<std::string, bool>::iterator it = opMembers.begin(); it != opMembers.end(); it++)
			{
				if (it->second)
					_srv->getClient(it->first)->receive_message(RPL_CHANAWAY(getName(), "PRIVMSG", "#"+target+"-feedback", message));
			}
		}
	} else if (args[1] == "broadcast") { // Operator send message to everyone 
		if (!client->isOper()) {
			client->receive_message(ERR_NOPRIVILEGES(getName(), client->getNickname()));
		} else {
			message = args[2];
			std::map<const int, Client *> allClient = _srv->getAllClient();
			for (std::map<const int, Client *>::iterator it = allClient.begin(); it != allClient.end(); it++)
			{
				it->second->receive_message(RPL_CHANAWAY(getName(), "PRIVMSG", "#broadcast", message));
			}
		}
	}
}