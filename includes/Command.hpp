/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:12:18 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 15:57:08 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
# include <sys/socket.h>

# include "Server.hpp"
# include "Channel.hpp"
# include "Client.hpp"

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

std::vector<std::string> commaSeperator(std::string arg);

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

class Part : public Command
{
	public:
		Part(Server * srv);
		~Part();

		void execute(Client * client, std::vector<std::string> &args);
};

class PrivMsg : public Command
{
	public:
		PrivMsg(Server * srv);
		~PrivMsg();

		void execute(Client * client, std::vector<std::string> &args);
};

class Quit : public Command
{
	public:
		Quit(Server * srv);
		~Quit();

		void execute(Client * client, std::vector<std::string> &args);
};

class Notice : public Command
{
	public:
		Notice(Server * srv);
		~Notice();

		void execute(Client * client, std::vector<std::string> &args);
};

class Names : public Command
{
	public:
		Names(Server * srv);
		~Names();

		void execute(Client * client, std::vector<std::string> &args);
};

class Oper : public Command
{
	public:
		Oper(Server * srv);
		~Oper();

		void execute(Client * client, std::vector<std::string> &args);
};

class Mode : public Command
{
	public:
		Mode(Server * srv);
		~Mode();

		void execute(Client * client, std::vector<std::string> &args);
		void getMode();
};

class Time : public Command
{
	public:
		Time(Server * srv);
		~Time();

		void execute(Client * client, std::vector<std::string> &args);
};

class Ping : public Command
{
	public:
		Ping(Server * srv);
		~Ping();

		void execute(Client * client, std::vector<std::string> &args);
};

class Pong : public Command
{
	public:
		Pong(Server * srv);
		~Pong();

		void execute(Client * client, std::vector<std::string> &args);
};

#endif