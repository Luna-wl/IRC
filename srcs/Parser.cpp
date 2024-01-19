/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:50:18 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 01:47:42 by wluedara         ###   ########.fr       */
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
	_cmd["PRIVMSG"] = new PrivMsg(srv);
	_cmd["LIST"] = new List(srv);
}

Parser::~Parser()
{
	for (std::map<std::string, Command *>::iterator it = _cmd.begin(); it != _cmd.end(); it++)
	{
		delete it->second;
	}
}

// void Parser::welcomeMessage(Client *client) {
	
// }

void Parser::analyze(Client *client, std::string &text) {
    // // client._nickname = "New Client 001";
	// std::cout << "receive [" << client->getFd() << "]: " << text << std::endl;
	// std::cout << "hi" << std::endl;
	// std::string temp_text;
	// std::vector<std::string> args;
	// std::stringstream ssin(text);
	// while (getline(ssin, temp_text, ' ')){
	// 	args.push_back(temp_text);
	// }
	// if (args.empty())
	// 	return ;
	// // create function check if cliet is registered
	// // if (client->isRegist() == false) {
	// // 	client->receive_message(ERR_NOTREGISTERED(_srv->getName()));
	// // 	return ;
	// // }
	// try {
	// 	_cmd[args[0]]->execute(client, args);
	// }
	// catch (std::exception &e) {
	// 	std::cerr << "Invalid command!" << std::endl;
	// }
	    // client._nickname = "New Client 001";
	std::cout << "receive [" << client->getFd() << "]: " << text << std::endl;

	std::string temp_text;
	std::vector<std::string> args;
    std::stringstream ssin(text);
    while (ssin.good()){
        ssin >> temp_text;
		args.push_back(temp_text);
    }
	// std::cout << "vector size: " << args.size() << std::endl;
	if (_cmd.count(args[0]))
		_cmd[args[0]]->execute(client, args);
}