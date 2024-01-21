/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:32:51 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/21 19:38:41 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Topic::Topic(Server * srv) : Command(srv) {}

Topic::~Topic() {}

void Topic::execute(Client * client, std::vector<std::string> &args) {
	std::cout << "[TOPIC] command" << std::endl;
	// if ( !client->isRegist() ) {
	// 	client->receive_message(ERR_NOTREGISTERED(_srv->getName()));
	// 	return;
	// }
	int num = args.size();
	if (num < 2)
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), "TOPIC"));
	else if (num == 2) {
		if (args[1][0] == '#') {
			// TOPIC #test	Checking the topic for "#test"
			try {
				if (_srv->getChannel(args[1])->getTopic() != "")
					client->receive_message(RPL_TOPIC(_srv->getName(), args[1], _srv->getChannel(args[1])->getTopic()));
				else
					client->receive_message(RPL_NOTOPIC(_srv->getName(), args[1]));
			} catch (std::exception &e) {
				client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), args[1]));
			}
		}
		else
			client->receive_message(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else if (num == 3) {
			// TOPIC #test : 	Clearing the topic on "#test"
			if (args[1][0] == ':')
				_srv->getChannel(args[1])->_setTopic("");
			else if (args[1][0] == '#') {
			// TOPIC #test :New topic 	Setting the topic on "#test" to "New topic".
				std::map<std::string, Channel *>::iterator it = _srv->getChannels().begin();
				while (it != _srv->getChannels().end()) {
					if (it->second->getName() == args[1]) {
						it->second->_setTopic(&args[2][1]);
						break;
					}
					it++;
				}
			}
			else
				client->receive_message(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), "TOPIC"));
	}
	else
		client->receive_message(ERR_TOOMANYARGUMENTS(_srv->getName(), "TOPIC"));
}

// ERR_NEEDMOREPARAMS (461)
// ERR_NOSUCHCHANNEL (403)
// ERR_NOTONCHANNEL (442)
// ERR_CHANOPRIVSNEEDED (482)
// RPL_NOTOPIC (331)
// RPL_TOPIC (332)
// RPL_TOPICWHOTIME (333)