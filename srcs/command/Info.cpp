/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:04 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Info::Info(Server * srv) : Command(srv) {}

Info::~Info() {}

void Info::execute(Client * client, std::vector<std::string> &args) {
	if (!client->isRegist()) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return ;
	}
  else if (args.size() != 1) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(client->getUsername(), "INFO"));
		return ;
	}
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], " ^-^            "));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "(O,O)           "));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "(_._)   SERVER INFO   "));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "-\"-\"-------------------"));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "Server name	: " + _srv->getName()));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "Port		: " + _srv->getPort()));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "Client number	: " + intToString(_srv->getClientNum())));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "Channel number	: " + intToString(_srv->getChannelNum())));
	client->receiveMessage(RPL_INFO(_srv->getName(), args[0], "-----------------------"));
}