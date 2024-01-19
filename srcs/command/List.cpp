/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:28 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/20 01:50:49 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

List::List(Server * srv) : Command(srv) {}

List::~List() {}

void List::execute(Client * client, std::vector<std::string> &args) {
	std::cout << "[LIST] command" << std::endl;
	// if ( !client->isRegist() ) {
	// 	client->receive_message(ERR_NOTREGISTERED(_srv->getName()));
	// 	return;
	// }
	int num = args.size();
	std::cout << "num = " << num << std::endl;
	if (num == 1) {
		if (_srv->getChannels().empty())
			client->receive_message(RPL_LISTEND(client->getUsername()));
		else {
			std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
			while (it != _srv->getChannels().end()) {
				client->receive_message("list channel");
				it++;
			}
		}
	}
	else if (num == 2) {
		std::cout << "list specific channel" << std::endl;
	}
	else {
		client->receive_message(ERR_TOOMANYARGUMENTS(client->getUsername(), "LIST"));
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