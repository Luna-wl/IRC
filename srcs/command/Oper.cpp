/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Oper.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:08:38 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 16:28:07 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Oper::Oper(Server * srv) : Command(srv) {}
Oper::~Oper() {}

void Oper::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), args[0]));
	}
	else if ( args.size() < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	}
	else
	{
		if ( args[1] != "Admin" ) {
			client->receive_message(ERR_NOOPERHOST(_srv->getName(), args[0]));
		} else if ( args[2] != "1234" ) {
			client->receive_message(ERR_PASSWDMISMATCH(_srv->getName(), args[0]));
		} else {
			client->setOper(true);
			client->receive_message(RPL_YOUREOPER(_srv->getName(), args[0]));
		}
	}
}