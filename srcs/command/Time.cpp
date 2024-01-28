/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:40:45 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/28 19:15:47 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Time::Time(Server * srv) : Command(srv) {}
Time::~Time() {}

void Time::execute(Client * client, std::vector<std::string> & args) {
	client->receiveMessage(RPL_TIME(client->source(), args[0], _srv->getName(), _srv->time(0), _srv->time(2)));
}