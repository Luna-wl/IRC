/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:37 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/26 16:57:27 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

User::User(Server * srv) : Command(srv) {}
User::~User() {}

void User::execute(Client * client, std::vector<std::string> & args)
{
	
	if ( args.size() < 5) {
		client->recieveMessage(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( args.size() > 5 ) {
		client->recieveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), args[0]));
	}
	else if ( !client->isAuth() ) {
		client->recieveMessage(ERR_NOTAUTHENTICATED(_srv->getName(), client->getNickname()));
	}
	else if ( client->isRegist() ) {
		client->recieveMessage(ERR_ALREADYREGISTRED(_srv->getName(), client->getNickname()));
	}
	else
	{
		client->setUsername(args[1]);
		client->setFullname(args[4]);
		if (!client->getNickname().empty() && client->getNickname() != "*")
		{		
			client->setRegist(true);
			welcomeClient(client, _srv);
		}
	}
}