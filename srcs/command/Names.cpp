/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Names.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:42:31 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Names::Names(Server * srv) : Command(srv) {}
Names::~Names() {}

std::string getSymbol(Channel * channel)
{
	std::string symbol;
	if (channel->isKeyMode())
		symbol = "*";
	else
		symbol = "=";
	return symbol;
}

std::string getUserPrefix(Client * client)
{
	std::string nick = client->getNickname();
	if (client->isOper())
		nick = "@" + nick;
	return nick;
}

void Names::execute(Client * client, std::vector<std::string> & args)
{
 	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() == 1 )
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	else {
		std::vector<std::string> channels = commaSeperator(args[1]);
		for(std::vector<std::string>::iterator it = channels.begin();it != channels.end(); it++)
		{
			std::string channel_name = *it;
			if (channel_name[0] != '#' || channel_name.size() == 1) {
				client->receiveMessage(ERR_BADCHANMASK(_srv->getName(), args[0], channel_name));
				continue;
			}
			channel_name.erase(0, 1);

			Channel * channel;
			if (!_srv->isChanExist(channel_name))
			{
				client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), args[0], channel_name));
				continue;
			}

			channel = _srv->getChannel(channel_name);
			std::string symbol = getSymbol(channel);

			std::map<std::string, Client *> member = channel->getMember();
			std::string nick;
			for (std::map<std::string, Client *>::iterator it = member.begin(); it != member.end(); it++)
				nick += getUserPrefix(it->second) + " "; // not yet (add prefix @op_user)
			client->receiveMessage(RPL_NAMREPLY(client->source(), args[0], symbol, "#" + channel_name, nick));
			client->receiveMessage(RPL_ENDOFNAMES(client->source(), args[0], "#" + channel_name));
		}
	}
}