/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:28 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/21 21:00:50 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

List::List(Server * srv) : Command(srv) {}

List::~List() {}

void List::execute(Client * client, std::vector<std::string> &args) {
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	}
	int num = args.size();
	std::cout << "num = " << num << std::endl;
	if (num == 1) {
		// LIST ALL CHANNELS
		if (_srv->getChannels().empty())
			client->receive_message(RPL_LISTEND(client->getUsername()));
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

// RPL_LISTSTART (321) 
//   "<client> Channel :Users  Name"
// Sent as a reply to the LIST command, this numeric marks the start of a channel list. As noted in the command description, this numeric MAY be skipped by the server so clients MUST NOT depend on receiving it.

// RPL_LIST (322) 
//   "<client> <channel> <client count> :<topic>"
// Sent as a reply to the LIST command, this numeric sends information about a channel to the client. 
//<channel> is the name of the channel. 
//<client count> is an integer indicating how many clients are joined to that channel. 
//<topic> is the channel’s topic (as set by the TOPIC command).

// RPL_LISTEND (323) 
//   "<client> :End of /LIST"
// Sent as a reply to the LIST command, this numeric indicates the end of a LIST response.