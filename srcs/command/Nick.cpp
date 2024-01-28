/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:16:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 19:39:14 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Nick::Nick(Server * srv) : Command(srv) {}

Nick::~Nick() {}

void Nick::execute(Client * client, std::vector<std::string> &args)
{
	if (!client->isAuth()) {
		client->receiveMessage(ERR_NOTAUTHENTICATED(_srv->getName(), client->getNickname()));
	}
	else if (args.size() > 2) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else if (args[1].empty()) {
		client->receiveMessage(ERR_NONICKNAMEGIVEN(_srv->getName(), client->getNickname()));
	}
	else if (args[1][0] == '#' || args[1][0] == ':' || args[1][0] == '$' || 
		args[1].find_first_of(" \t\n\r\f\v.,*?!@") != std::string::npos) {
		client->receiveMessage(ERR_ERRONEUSNICKNAME(_srv->getName(), client->getNickname(), args[1]));
	}
	else if (nickIsUsed(args[1])) {
		client->receiveMessage(ERR_NICKNAMEINUSE(_srv->getName(), client->getNickname(), args[1]));
	}
	else {
		client->setNickname(args[1]);
		if (!client->getUsername().empty()) {
			if (!client->isRegist())
				welcomeClient(client, _srv);
			client->setRegist(true);
		}
	}
}

bool Nick::nickIsUsed(std::string name)
{
	std::map<const int, Client *> clients	= _srv->getAllClient();
	for (std::map<const int, Client *>::iterator it = clients.begin(); it != clients.end(); it++) {
		if (it->second->getNickname() == name)
			return true;
	}
	return false;
}