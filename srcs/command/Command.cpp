/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:00:27 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 19:17:34 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Command::Command(Server * srv) : _srv(srv) {}

Command::~Command() {}

std::vector<std::string> commaSeperator(std::string arg)
{
	std::vector<std::string> ret;
	size_t pos = 0;
	std::string tmp; 
	do {
		pos = arg.find(",");
		tmp = arg.substr(0, pos);
        if (!tmp.empty())
            ret.push_back(tmp);
        arg.erase(0, pos + 1);
	} while (pos != std::string::npos);
	return (ret);
}

void welcomeClient(Client * client, Server * server)
{
	client->receiveMessage(RPL_WELCOME(client->source(), server->getName(), client->source()));
	client->receiveMessage(RPL_YOURHOST(client->source(), server->getName()));
	client->receiveMessage(RPL_CREATED(client->source(), server->getCreateTime()));
}