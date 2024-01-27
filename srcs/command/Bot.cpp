/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:50:44 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/27 23:05:06 by csantivimol      ###   ########.fr       */
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
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return ;
	} else if ( args.size() < 3 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return ;
	}
	
	std::string target;
	std::string message;

	if ( args[1][0] == '#') { // user send message to "channel operator"
		target = args[1].erase(0, 1);
		Channel * channel = _srv->getChannel(target);
		message = args[2];
		if (!channel)
			client->recieveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
		else if (!client->getChannel(target))
			client->recieveMessage(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), "#" + target));
		else
		{
			std::map<std::string, bool> opMembers = channel->getOpMember();
			for (std::map<std::string, bool>::iterator it = opMembers.begin(); it != opMembers.end(); it++)
			{
				if (it->second)
					_srv->getClient(it->first)->recieveMessage(RPL_CHANAWAY(getName(), "PRIVMSG", "#"+target+"-feedback", message));
			}
		}
	} else if (args[1] == "broadcast") { // Operator send message to everyone 
		if (!client->isOper()) {
			client->recieveMessage(ERR_NOPRIVILEGES(getName(), client->getNickname()));
		} else {
			message = args[2];
			std::map<const int, Client *> allClient = _srv->getAllClient();
			for (std::map<const int, Client *>::iterator it = allClient.begin(); it != allClient.end(); it++)
			{
				it->second->recieveMessage(RPL_CHANAWAY(getName(), "PRIVMSG", "#broadcast", message));
			}
		}
	}
	else
		client->recieveMessage(ERR_UNKNOWNCOMMAND(getName(), client->getNickname(), args[0] + " " + args[1]));
}