/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:08:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 23:18:09 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Mode::Mode(Server * srv) : Command(srv) {}
Mode::~Mode() {}

void Mode::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), args[0]));
		return;
	} else if ( args.size() < 2 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), args[0]));
		return;
	}

	std::string target = args[1];
	std::string mode = args[2];

	
	if ( target.at(0) == '#') { // change channel mode
		
	}
	else { // change user mode
		client->receive_message(ERR_UNKNOWNMODE(_srv->getName(), args[1], args[2]));
	}
}