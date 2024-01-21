/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:40:45 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/21 19:40:46 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Time::Time(Server * srv) : Command(srv) {}
Time::~Time() {}

void Time::execute(Client * client, std::vector<std::string> & args)
{
    client->receive_message(RPL_TIME(client->source(), args[0], _srv->getName(), _srv->time(0), _srv->time(2)));
}