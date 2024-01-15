/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:16:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/15 23:29:44 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Nick::Nick(Server * srv) : Command(srv) {}

Nick::~Nick() {}

void Nick::execute(Client * client, std::vector<std::string> &args)
{
	std::cout << "[NICK] executed" << std::endl;

	if (args[1].empty()) {
		client->receive_message(ERR_NONICKNAMEGIVEN);
	} else if (args[1][0] == '#' || args[1][0] == ':' || args[1].find(" \t\n\r\f\v") != std::string::npos) {
		client->receive_message(ERR_ERRONEUSNICKNAME(args[1]));
	} else if (nickIsUsed(args[1])){
		client->receive_message(ERR_NICKNAMEINUSE(args[1]));
	} else {
		client->setNickname(args[1]);
		client->send_debug("set nickname > " + client->getNickname());
	}
}

bool Nick::nickIsUsed(std::string name)
{
	std::map<const int, Client *> clients	= _srv->getClient();
	for (std::map<const int, Client *>::iterator it = clients.begin(); it != clients.end(); it++)
	{
		if (it->second->getNickname() == name)
			return true;
	}
	return false;
}