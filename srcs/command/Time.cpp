/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:40:45 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 22:05:28 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Time::Time(Server * srv) : Command(srv) {}
Time::~Time() {}

void Time::execute(Client * client, std::vector<std::string> & args) {
    client->receive_message(RPL_TIME(client->source(), args[0], _srv->getName(), _srv->time(0), _srv->time(2)));
}