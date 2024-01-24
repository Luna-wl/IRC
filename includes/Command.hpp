/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:12:18 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 23:06:39 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
# include <string>
# include <sys/socket.h>

# include "Server.hpp"
# include "Channel.hpp"
# include "Client.hpp"

class Command
{
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

class Invite : public Command
{
	public:
		Invite(Server * srv);
		~Invite();

		void execute(Client * client, std::vector<std::string> &args);
};

class Part : public Command
{
	public:
		Part(Server * srv);
		~Part();

		void execute(Client * client, std::vector<std::string> &args);
};

class Kick : public Command
{
	public:
		Kick(Server * srv);
		~Kick();

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

class Quit : public Command
{
	public:
		Quit(Server * srv);
		~Quit();


		void execute(Client * client, std::vector<std::string> &args);
};

class List : public Command
{
	public:
		List(Server * srv);
		~List();

	void execute(Client * client, std::vector<std::string> &args);
};

class Notice : public Command
{
	public:
		Notice(Server * srv);
		~Notice();

		void execute(Client * client, std::vector<std::string> &args);
};

class Info : public Command
{
	public:
		Info(Server * srv);
		~Info();

	void execute(Client * client, std::vector<std::string> &args);
};

class Names : public Command
{
	public:
		Names(Server * srv);
		~Names();

		void execute(Client * client, std::vector<std::string> &args);
};

class Help : public Command
{
	public:
		Help(Server * srv);
		~Help();

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
	private:
		bool _validMode(std::string mode);
		void _setInviteMode(Channel* channel, bool flag, std::vector<std::string> params);
		void _setTopicMode(Channel* channel, bool flag, std::vector<std::string> params);
		void _setKeyMode(Channel* channel, bool flag, std::vector<std::string> params);
		void _setChanOperMode(Client* client, Channel* channel, bool flag, std::vector<std::string> params);
		void _setLimitMode(Channel* channel, bool flag, std::vector<std::string> params);
	public:
		Mode(Server * srv);
		~Mode();

		void execute(Client * client, std::vector<std::string> &args);
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

class Bot : public Command
{
	public:
		Bot(Server * srv);
		~Bot();

		void execute(Client * client, std::vector<std::string> &args);
		std::string getName();
};

#endif