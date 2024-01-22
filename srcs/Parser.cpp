/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:50:18 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/23 00:06:19 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Parser.hpp"

Parser::Parser(Server * srv)
{
	_srv = srv;
	_cmd["NICK"] = new Nick(srv);
	_cmd["PASS"] = new Pass(srv);
	_cmd["USER"] = new User(srv);
	_cmd["JOIN"] = new Join(srv);
	_cmd["INVITE"] = new Invite(srv);
	_cmd["PART"] = new Part(srv);
	_cmd["KICK"] = new Kick(srv);
	_cmd["PRIVMSG"] = new PrivMsg(srv);
	_cmd["LIST"] = new List(srv);
	_cmd["TOPIC"] = new Topic(srv);
	_cmd["HELP"] = new Help(srv);
	_cmd["INFO"] = new Info(srv);
	_cmd["QUIT"] = new Quit(srv);
	_cmd["NAMES"] = new Names(srv);
	_cmd["NOTICE"] = new Notice(srv);
	_cmd["OPER"] = new Oper(srv);
	_cmd["MODE"] = new Mode(srv);
	_cmd["TIME"] = new Time(srv);
	_cmd["PING"] = new Ping(srv);
	_cmd["PONG"] = new Pong(srv);
}

Parser::~Parser()
{
	for (std::map<std::string, Command *>::iterator it = _cmd.begin(); it != _cmd.end(); it++)
	{
		delete it->second;
	}
}

void Parser::analyze(Client *client, std::string &text) {
	std::cout << "receive [" << client->getFd() << "]: " << text << std::endl;

	std::string temp_text;
	std::vector<std::string> args;
	std::stringstream ssin(text);
	while (ssin >> temp_text) {
		size_t colon = temp_text.find(':');
		if (colon != std::string::npos) {
			temp_text.erase(std::remove(temp_text.begin(), temp_text.end(), ':'), temp_text.end());
			std::string next_text;
			while (ssin.good())
			{
				ssin >> next_text;
				temp_text += " " + next_text;
			}
		}
		args.push_back(temp_text);
	}
	std::cout << "args.size(): " << args.size() << std::endl;
	for (unsigned long i = 0; i < args.size(); i++)
		std::cout << "args[" << i << "]: " << args[i] << std::endl;
	if (_cmd.count(args[0]))
		_cmd[args[0]]->execute(client, args);
	else
		client->receive_message(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), args[0]));
} 