/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:41 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 22:12:47 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Quit::Quit(Server * srv) : Command(srv) {}
Quit::~Quit() {}

void Quit::execute(Client * client, std::vector<std::string> & args) {
	(void) args;
	// disconnect with server
	_srv->clientDisconnect(client->getFd());
}