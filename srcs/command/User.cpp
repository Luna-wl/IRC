/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:37 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

User::User(Server * srv) : Command(srv) {}
User::~User() {}

void User::execute(Client * client, std::vector<std::string> & args)
{
	
	if ( !client->isAuth() ) {
		client->receiveMessage(ERR_NOTAUTHENTICATED(_srv->getName(), client->getNickname()));
	}
	else if ( client->isRegist() && !client->getFullname().empty() ) {
		client->receiveMessage(ERR_ALREADYREGISTRED(_srv->getName(), client->getNickname()));
	}
	else if ( args.size() < 5) {
		client->receiveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( args.size() > 5 ) {
		client->receiveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else {
		client->setUsername(args[1]);
		client->setFullname(args[4]);
		if (!client->getNickname().empty() && client->getNickname() != "*") {		
			client->setRegist(true);
			welcomeClient(client, _srv);
		}
	}
}