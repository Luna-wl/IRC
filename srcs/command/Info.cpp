/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:04 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/22 00:21:37 by wluedara         ###   ########.fr       */
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
	std::string message = "\n\n ^ ^            \n";
	message += "(O,O)           \n";
	message += "(   )   SERVER INFO   \n";
	message += "-\"-\"-------------------\n";
	message += "Server name	: " + _srv->getName() + "\n";
	message += "Port		: " + _srv->getPort() + "\n";
	message += "Client number	: " + std::to_string(_srv->getClientNum()) + "\n";
	message += "Channel number	: " + std::to_string(_srv->getChannelNum()) + "\n";
	message += "-----------------------\n";
	client->receive_message(RPL_INFO(_srv->getName(), args[0], message));
}