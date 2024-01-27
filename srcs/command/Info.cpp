/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Info.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:04 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/27 18:35:06 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Info::Info(Server * srv) : Command(srv) {}

Info::~Info() {}

void Info::execute(Client * client, std::vector<std::string> &args) {
	if (!client->isRegist()) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return ;
	} else if (args.size() != 1) {
		client->recieveMessage(ERR_TOOMANYARGUMENTS(client->getUsername(), "INFO"));
		return ;
	}
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "^-^            "));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "(O,O)           "));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "(_._)   SERVER INFO   "));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "-\"-\"-------------------"));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "Server name	: " + _srv->getName()));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "Port		: " + _srv->getPort()));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "Client number	: " + intToString(_srv->getClientNum())));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "Channel number	: " + intToString(_srv->getChannelNum())));
	client->recieveMessage(RPL_INFO(_srv->getName(), args[0], "-----------------------"));
}