/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:04 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/25 13:54:23 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Info::Info(Server * srv) : Command(srv) {}

Info::~Info() {}

void Info::execute(Client * client, std::vector<std::string> &args) {
	if (args.size() != 1) {
		client->receive_message(ERR_TOOMANYARGUMENTS(client->getUsername(), "INFO"));
		return ;
	}
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "^-^            "));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "(O,O)           "));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "(_._)   SERVER INFO   "));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "-\"-\"-------------------"));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "Server name	: " + _srv->getName()));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "Port		: " + _srv->getPort()));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "Client number	: " + std::to_string(_srv->getClientNum())));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "Channel number	: " + std::to_string(_srv->getChannelNum())));
	client->receive_message(RPL_INFO(_srv->getName(), args[0], "-----------------------"));
}