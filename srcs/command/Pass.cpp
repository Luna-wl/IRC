/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:48 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/18 18:46:43 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Pass::Pass(Server * srv) : Command(srv) {}
Pass::~Pass() {}

void Pass::execute(Client * client, std::vector<std::string> & args)
{
	if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	}
	else if ( client->isAuth() ) {
		client->receive_message(ERR_ALREADYAUTHENTICATED(_srv->getName()));
	}
	else if ( args[1] != _srv->getPass() ) {
		client->receive_message(ERR_PASSWDMISMATCH(_srv->getName()));
	}
	else if ( args[1] == _srv->getPass() ) {
		client->setAuth(true);
	}
}