/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:48 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Pass::Pass(Server * srv) : Command(srv) {}
Pass::~Pass() {}

void Pass::execute(Client * client, std::vector<std::string> & args)
{
	if ( args.size() == 1 ) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( client->isAuth() ) {
		client->recieveMessage(ERR_ALREADYAUTHENTICATED(_srv->getName(), client->getNickname()));
	}
	else if ( args[1] != _srv->getPass() ) {
		client->recieveMessage(ERR_PASSWDMISMATCH(_srv->getName(), client->getNickname()));
	}
	else if ( args[1] == _srv->getPass() ) {
		client->setAuth(true);
	}
}