/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:28 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/27 23:52:43 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

List::List(Server * srv) : Command(srv) {}

List::~List() {}

void List::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	int num = args.size();
	if (num == 1) {
		// LIST ALL CHANNELS
		if (_srv->getChannels().empty())
			client->recieveMessage(RPL_LISTEND(_srv->getName()));
		else {
			client->recieveMessage("+-----LIST CHANNEL-----+");
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			while (it != _srv->getChannels().end()) {
				client->recieveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				it++;
			}
			client->recieveMessage(RPL_LISTEND(_srv->getName()));
		}
	}
	else if (num == 2) {
		// LIST <channel> SPECIFIC CHANNEL
		if (args[1][0] == '#') {
			std::string target = args[1];
			target = target.erase(0, 1);
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().find(target);
			if (it != _srv->getChannels().end()) {
				client->recieveMessage("+-----LIST CHANNEL-----+");
				client->recieveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				client->recieveMessage(RPL_LISTEND(_srv->getName()));
			}
			else {
				client->recieveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			}
		}
		else if (args[1][0] == '>') {
			// LIST >num SPECIFIC CHANNEL CLIENTS NUM
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			int num = atoi(args[1].substr(1).c_str());
			client->recieveMessage("+-----LIST CHANNEL-----+");
			while (it != _srv->getChannels().end()) {
				if (it->second->getClietNum() > num) {
					client->recieveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				}
				it++;
			}
			client->recieveMessage(RPL_LISTEND(_srv->getName()));
		}
		else {
			client->recieveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
		}
	}
	else {
		client->recieveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), "LIST"));
	}
}

