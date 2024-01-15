/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:50:18 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/15 15:57:16 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
	_cmd["NICK"] = new Nick();
}

Parser::~Parser()
{
	delete _cmd["NICK"];
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
		args.push_back(temp_text);
    }

	// std::cout << "vector size: " << args.size() << std::endl;
	if (_cmd.count(args[0]))
		_cmd[args[0]]->execute(client, args);
}