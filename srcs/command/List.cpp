/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:28 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

List::List(Server * srv) : Command(srv) {}

List::~List() {}

void List::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	int num = args.size();
	if (num == 1) {
		// LIST ALL CHANNELS
		if (_srv->getChannels().empty())
			client->receiveMessage(RPL_LISTEND(_srv->getName()));
		else {
			client->receiveMessage("+-----LIST CHANNEL-----+");
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			while (it != _srv->getChannels().end()) {
				client->receiveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				it++;
			}
			client->receiveMessage(RPL_LISTEND(_srv->getName()));
		}
	}
	else if (num == 2) {
		// LIST <channel> SPECIFIC CHANNEL
		if (args[1][0] == '#') {
			std::string target = args[1];
			target = target.erase(0, 1);
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().find(target);
			if (it != _srv->getChannels().end()) {
				client->receiveMessage("+-----LIST CHANNEL-----+");
				client->receiveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				client->receiveMessage(RPL_LISTEND(_srv->getName()));
			}
			else {
				client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			}
		}
		else if (args[1][0] == '>') {
			// LIST >num SPECIFIC CHANNEL CLIENTS NUM
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			int num = atoi(args[1].substr(1).c_str());
			client->receiveMessage("+-----LIST CHANNEL-----+");
			while (it != _srv->getChannels().end()) {
				if (it->second->getClietNum() > num) {
					client->receiveMessage(RPL_LIST(_srv->getName(), "#" + it->second->getName(), intToString(it->second->getClietNum()), it->second->getTopic()));
				}
				it++;
			}
			client->receiveMessage(RPL_LISTEND(_srv->getName()));
		}
		else {
			client->receiveMessage(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
		}
	}
	else {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), "LIST"));
	}
}

