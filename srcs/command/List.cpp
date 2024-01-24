/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:28 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/22 01:02:14 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

List::List(Server * srv) : Command(srv) {}

List::~List() {}

void List::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return ;
	}
	int num = args.size();
	if (num == 1) {
		// LIST ALL CHANNELS
		if (_srv->getChannels().empty())
			client->receive_message(RPL_LISTEND(_srv->getName()));
		else {
			client->receive_message("+-----LIST CHANNEL-----+");
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			while (it != _srv->getChannels().end()) {
				client->receive_message(RPL_LIST(it->second->getName(), std::to_string(it->second->getClietNum()), it->second->getTopic()));
				it++;
			}
		}
	}
	else if (num == 2) {
		// LIST <channel> SPECIFIC CHANNEL
		if (args[1][0] == '#') {
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().find(args[1]);
			if (it != _srv->getChannels().end()) {
				client->receive_message("+-----LIST CHANNEL-----+");
				client->receive_message(RPL_LIST(it->second->getName(), std::to_string(it->second->getClietNum()), it->second->getTopic()));
			}
			else {
				client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			}
		}
		else if (args[1][0] == '>') {
			// LIST >num SPECIFIC CHANNEL CLIENTS NUM
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			int num = std::stoi(args[1].substr(1));
			while (it != _srv->getChannels().end()) {
				if (it->second->getClietNum() == num) {
					client->receive_message("+-----LIST CHANNEL-----+");
					client->receive_message(RPL_LIST(it->second->getName(), std::to_string(it->second->getClietNum()), it->second->getTopic()));
				}
				it++;
			}
		}
		else {
			client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
		}
	}
	else {
		client->receive_message(ERR_TOOMANYARGUMENTS(_srv->getName(), "LIST"));
	}
}

