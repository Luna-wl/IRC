/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:04 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/21 19:48:40 by tkraikua         ###   ########.fr       */
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
	// client->receive_message(RPL_INFO(client->getUsername()));
	// client->receive_message("===== SERVER INFO =====");
	// client->receive_message("Server name	: " + _srv->getName());
	// client->receive_message("Port		: " + _srv->getPort());
	// client->receive_message("Client number	: " + std::to_string(_srv->getClientNum()));
	// client->receive_message("Channel number	: " + std::to_string(_srv->getChannelNum()));
	std::string message = "\n===== SERVER INFO =====\n";
	message += "Server name	: " + _srv->getName() + "\n";
	message += "Port		: " + _srv->getPort() + "\n";
	message += "Client number	: " + std::to_string(_srv->getClientNum()) + "\n";
	message += "Channel number	: " + std::to_string(_srv->getChannelNum());
	client->receive_message(RPL_INFO(_srv->getName(), args[0], message));
}