/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Quit.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:32:41 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 02:56:14 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Quit::Quit(Server * srv) : Command(srv) {}
Quit::~Quit() {}

void Quit::execute(Client * client, std::vector<std::string> & args)
{
    // disconnect with server
    _srv->clientDisconnect(client->getFd());
}