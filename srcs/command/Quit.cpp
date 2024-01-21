/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:41 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/21 19:39:50 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Quit::Quit(Server * srv) : Command(srv) {}
Quit::~Quit() {}

void Quit::execute(Client * client, std::vector<std::string> & args)
{
    (void) args;
    // disconnect with server
    _srv->clientDisconnect(client->getFd());
}