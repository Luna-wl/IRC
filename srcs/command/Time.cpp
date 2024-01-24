/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:40:45 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/24 20:59:11 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Time::Time(Server * srv) : Command(srv) {}
Time::~Time() {}

void Time::execute(Client * client, std::vector<std::string> & args)
{
    client->recieveMessage(RPL_TIME(client->source(), args[0], _srv->getName(), _srv->time(0), _srv->time(2)));
}