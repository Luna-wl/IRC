/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:31:37 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/16 19:35:11 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

User::User(Server * srv) : Command(srv) {}
User::~User() {}

void User::execute(Client * client, std::vector<std::string> & args)
{
	
	if ( args.size() < 5) {
		client->receive_message(ERR_NEEDMOREPARAMS(args[0]));
	}
	else if ( !client->isAuth() ) {
		client->receive_message(ERR_NOTAUTHENTICATED);
	}
	else if ( client->isRegist() ) {
		client->receive_message(ERR_ALREADYREGISTRED);
	}
	else
	{
		client->setUsername(args[1]);
		client->setFullname(args[4]);
		client->send_debug("Username : " + client->getUsername());
		client->send_debug("Fullname : " + client->getFullname());
		client->setRegist(true);
	}
}