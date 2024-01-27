/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:41 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 00:51:32 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Quit::Quit(Server * srv) : Command(srv) {}
Quit::~Quit() {}

void Quit::execute(Client * client, std::vector<std::string> & args)
{
    (void) args;
    _srv->clientDisconnect(client->getFd());
}