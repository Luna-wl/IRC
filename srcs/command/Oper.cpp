/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:08:38 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Oper::Oper(Server * srv) : Command(srv) {}
Oper::~Oper() {}

void Oper::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receiveMessage(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() < 3 ) {
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( args.size() > 3 ) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else
	{
		if ( args[1] != "Admin" ) {
			client->receiveMessage(ERR_NOOPERHOST(_srv->getName(), client->getNickname()));
		} else if ( args[2] != "1234" ) {
			client->receiveMessage(ERR_PASSWDMISMATCH(_srv->getName(), client->getNickname()));
		} else {
			client->setOper(true);
			client->receiveMessage(RPL_YOUREOPER(_srv->getName(), args[0]));
		}
	}
}