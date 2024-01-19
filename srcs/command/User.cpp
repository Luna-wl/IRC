/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:37 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 01:30:16 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

User::User(Server * srv) : Command(srv) {}
User::~User() {}

void User::execute(Client * client, std::vector<std::string> & args)
{
	
	if ( args.size() < 5) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
	}
	else if ( !client->isAuth() ) {
		client->receive_message(ERR_NOTAUTHENTICATED(_srv->getName()));
	}
	else if ( client->isRegist() ) {
		client->receive_message(ERR_ALREADYREGISTRED(_srv->getName()));
	}
	else
	{
		client->setUsername(args[1]);
		client->setFullname(args[4]);
		client->send_debug("Username : " + client->getUsername());
		client->send_debug("Fullname : " + client->getFullname());
		if (!client->getNickname().empty())
			client->setRegist(true);
	}
}