/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:16:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 22:39:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Nick::Nick(Server * srv) : Command(srv) {}

Nick::~Nick() {}

void Nick::execute(Client * client, std::vector<std::string> &args)
{
	std::cout << "[NICK] executed" << std::endl;

	if (!client->isAuth()) {
		client->receive_message(ERR_NOTAUTHENTICATED(_srv->getName()));
	}
	else if (args[1].empty()) {
		client->receive_message(ERR_NONICKNAMEGIVEN(_srv->getName()));
	} else if (args[1][0] == '#' || args[1][0] == ':' || args[1][0] == '$' || 
        args[1].find_first_of(" \t\n\r\f\v.,*?!@") != std::string::npos) {
		client->receive_message(ERR_ERRONEUSNICKNAME(_srv->getName(), args[1]));
	} else if (nickIsUsed(args[1])){
		client->receive_message(ERR_NICKNAMEINUSE(_srv->getName(), args[1]));
	} else {
		client->setNickname(args[1]);
		client->send_debug("set nickname > " + client->getNickname());
		if (!client->getUsername().empty())
			client->setRegist(true);
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