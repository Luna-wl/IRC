/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:37 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/21 20:06:14 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

User::User(Server * srv) : Command(srv) {}
User::~User() {}

void User::execute(Client * client, std::vector<std::string> & args)
{
	
	if ( args.size() < 5) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
	}
	else if ( !client->isAuth() ) {
		client->receive_message(ERR_NOTAUTHENTICATED(_srv->getName(), client->getNickname()));
	}
	else if ( client->isRegist() ) {
		client->receive_message(ERR_ALREADYREGISTRED(_srv->getName(), client->getNickname()));
	}
	else
	{
		client->setUsername(args[1]);
		client->setFullname(args[4]);
		if (!client->getNickname().empty() && client->getNickname() != "*")
			client->setRegist(true);
	}
}