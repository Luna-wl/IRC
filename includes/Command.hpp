/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:12:18 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/15 23:31:13 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
# include <sys/socket.h>

# include "Client.hpp"
# include "replies.hpp"

class Server;

class Command
{
	private:
		// std::vector<string>    _args;
		// std::string            _cmd;
		// std::string            _prefix;
		// bool                   _valid;
	protected:
		Server * _srv;
	public:
		Command(Server * srv);
		virtual ~Command();

		virtual void execute(Client * client, std::vector<std::string> &args) = 0;
};

/* Command */

class Pass : public Command
{
	public:
		Pass(Server * srv);
		~Pass();

		void execute(Client * client, std::vector<std::string> &args);
};

class Nick : public Command
{
	public:
		Nick(Server * srv);
		~Nick();

		void execute(Client * client, std::vector<std::string> &args);
		bool nickIsUsed(std::string name);
};

class User : public Command
{
	public:
		User(Server * srv);
		~User();

		void execute(Client * client, std::vector<std::string> &args);
};

# include "Server.hpp"

#endif