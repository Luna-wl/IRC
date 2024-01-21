/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 22:08:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/21 19:40:41 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Mode::Mode(Server * srv) : Command(srv) {}
Mode::~Mode() {}

void Mode::execute(Client * client, std::vector<std::string> &args)
{
	if ( !client->isRegist() ) {
		client->receive_message(ERR_NOTREGISTERED(_srv->getName(), client->getNickname()));
		return;
	} else if ( args.size() < 3 ) {
		client->receive_message(ERR_NEEDMOREPARAMS(_srv->getName(), client->getNickname(), args[0]));
		return;
	}

	std::string target = args[1];
	std::string mode = args[2];
	if (!_validMode(mode)) {
		client->receive_message(ERR_UMODEUNKNOWNFLAG(_srv->getName(), client->getNickname()));
		return;
	}
		
	bool mode_flag = mode[0] == '+' ? true : false;;
	char mode_char = mode[1];


	if ( target.at(0) == '#') { // change channel mode
		std::string channel_name = target.erase(0, 1);
		Channel * channel = _srv->getChannel(channel_name);
		if (!channel) {
			client->receive_message(ERR_NOSUCHCHANNEL(_srv->getName(), client->getNickname(), channel_name));
			return ;
		} else if (!client->getChannel(channel_name)) {
			client->receive_message(ERR_NOTONCHANNEL(_srv->getName(), client->getNickname(), channel_name));
			return ;
		} else if (!client->isOper() && !channel->isChanOp(client->getNickname())) {
			client->receive_message(ERR_CHANOPRIVSNEEDED(_srv->getName(), client->getNickname(), channel_name));
			return ;
		}

		std::vector<std::string> params(args.begin() + 2, args.end());
		if (mode_char == 'i') {
			_setInviteMode(channel, mode_flag, params);
		} else if (mode_char == 't') {
			_setTopicMode(channel, mode_flag, params);
		} else if (mode_char == 'k') {
			_setKeyMode(channel, mode_flag, params);
		} else if (mode_char == 'o') {
			_setChanOperMode(channel, mode_flag, params);
		} else if (mode_char == 'l') {
			_setLimitMode(channel, mode_flag, params);
		} else {
			client->receive_message(ERR_UNKNOWNMODE(_srv->getName(), client->getNickname(), mode_char));
		}
	}
	else { // change user mode
		if (!_srv->get_client(target))
			client->receive_message(ERR_NOSUCHNICK(_srv->getName(), client->getNickname(), target));
		else
			client->receive_message(ERR_UNKNOWNMODE(_srv->getName(), client->getNickname(), mode_char));
	}
}

bool Mode::_validMode(std::string mode)
{
	if (mode.size() != 2)
		return false;
	else
	{
		if ((mode[0] == '-' || mode[0] == '+') && isalpha(mode[1]))
			return true;
		else
			return false;
	}
}

void Mode::_setInviteMode(Channel* channel, bool flag, std::vector<std::string> params)
{
	(void) params;
	channel->setInviteMode(flag);
}

void Mode::_setTopicMode(Channel* channel, bool flag, std::vector<std::string> params)
{
	(void) params;
	channel->setTopicMode(flag);
}

void Mode::_setKeyMode(Channel* channel, bool flag, std::vector<std::string> params)
{
	if (flag)
		channel->setKeyMode(flag, params[1]);
	else
		channel->setKeyMode(flag, "");
}

void Mode::_setChanOperMode(Channel* channel, bool flag, std::vector<std::string> params)
{
	if (params.size() > 1)
	{
		std::string nick = params[1];
		if (flag)
			channel->addChanOp(nick);
		else
			channel->removeChanOp(nick);
	}
}

void Mode::_setLimitMode(Channel* channel, bool flag, std::vector<std::string> params)
{
	if (flag){
		std::stringstream ss(params[1]);
		int limit;
		ss >> limit;
		if (params[1].empty())
			limit = channel->getLimit();
		channel->setLimitMode(flag, limit);
	}
	else
		channel->setLimitMode(flag, 0);
}