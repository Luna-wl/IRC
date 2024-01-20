/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:50:18 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 17:56:56 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

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

void Parser::analyze(Client *client, std::string &text)
{
    // client._nickname = "New Client 001";
	std::cout << "receive [" << client->getFd() << "]: " << text << std::endl;

	std::string temp_text;
	std::vector<std::string> args;
    std::stringstream ssin(text);
    while (ssin.good()){
        ssin >> temp_text;
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

	if (_cmd.count(args[0]))
		_cmd[args[0]]->execute(client, args);
	else
		client->receive_message(ERR_UNKNOWNCOMMAND(_srv->getName(), client->getNickname(), args[0]));
}