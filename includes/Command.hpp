/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:12:18 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/21 01:34:44 by wluedara         ###   ########.fr       */
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

class Join : public Command
{
	public:
		Join(Server * srv);
		~Join();

		void execute(Client * client, std::vector<std::string> &args);
};

class PrivMsg : public Command
{
	public:
		PrivMsg(Server * srv);
		~PrivMsg();

		void execute(Client * client, std::vector<std::string> &args);
};

class Topic : public Command
{
	public:
		Topic(Server * srv);
		~Topic();

		void execute(Client * client, std::vector<std::string> &args);
};

class List : public Command
{
	public:
		List(Server * srv);
		~List();

		void execute(Client * client, std::vector<std::string> &args);
};

class Info : public Command
{
	public:
		Info(Server * srv);
		~Info();

		void execute(Client * client, std::vector<std::string> &args);
};

class Help : public Command
{
	public:
		Help(Server * srv);
		~Help();

		void execute(Client * client, std::vector<std::string> &args);
};

# include "Server.hpp"

#endif