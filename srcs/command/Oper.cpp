/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:08:38 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Oper::Oper(Server * srv) : Command(srv) {}
Oper::~Oper() {}

void Oper::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->recieveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() < 3 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else
	{
		if ( args[1] != "Admin" ) {
			client->recieveMessage(ERR_NOOPERHOST(_srv->getName(), client->getNickname()));
		} else if ( args[2] != "1234" ) {
			client->recieveMessage(ERR_PASSWDMISMATCH(_srv->getName(), client->getNickname()));
		} else {
			client->setOper(true);
			client->recieveMessage(RPL_YOUREOPER(_srv->getName(), args[0]));
		}
	}
}