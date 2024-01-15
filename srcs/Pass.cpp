/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:06:48 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/15 18:16:40 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Pass::Pass(Server * srv) : Command(srv) {}
Pass::~Pass() {}

void Pass::execute(Client * client, std::vector<std::string> & args)
{
	if ( args.size() == 1 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(args[0]));
	}
	else if ( client->isRegist() ) {
		client->receive_message(ERR_ALREADYREGISTRED);
	}
	else if ( args[1] == _srv->getPass()) {
		client->setRegist(true);
	}
}