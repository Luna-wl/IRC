/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:00:27 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/26 16:57:08 by csantivi         ###   ########.fr       */
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
	while ((pos = arg.find(",")) != std::string::npos)
	{
		tmp = arg.substr(0, pos);
        if (!tmp.empty())
            ret.push_back(tmp);
        arg.erase(0, pos + 1);
	}
	tmp = arg.substr(0, pos);
	if (!tmp.empty())
		ret.push_back(tmp);
	return (ret);
}

void welcomeClient(Client * client, Server * server)
{
	client->recieveMessage(RPL_WELCOME(client->source(), server->getName(), client->source()));
	client->recieveMessage(RPL_YOURHOST(client->source(), server->getName()));
	client->recieveMessage(RPL_CREATED(client->source(), server->getCreateTime()));
}