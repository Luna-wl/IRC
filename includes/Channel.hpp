/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:08 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/21 19:33:38 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <map>

# include "Server.hpp"

class Client;

class Channel
{
	private:
		Server *						_srv;
		std::string						_name;
		std::map<std::string, Client *>	_members;
		std::map<std::string, bool>		_opMembers;
		std::string						_topic;
		std::string						_key;
		unsigned long					_userLimit;
		/* MODES */
		bool	_i; // Invite-only
		bool	_t; // restrict TOPIC
		bool	_k; // set key
		bool	_l; // user limit
	public:
		Channel(Server * srv, std::string name, std::string key);
		~Channel();

		void addMember(Client * member);
		void removeClient(Client * member);
		void addChanOp(std::string nick);
		void removeChanOp(std::string nick);
		bool isChanOp(std::string nick);

		void send_message(Client * member, std::string message);

		// getter
		std::string getName();

		int getClietNum();
		std::string getTopic();
		void _setTopic(std::string topic);
		std::string getKey();
		std::map<std::string, Client *> getMember();
		int	getLimit();

		

		bool isFull();
		
		/* get Modes */
		bool isInviteMode();
		bool isTopicMode();
		bool isKeyMode();
		bool isLimitMode();

		void setInviteMode(bool state);
		void setTopicMode(bool state);
		void setKeyMode(bool state, std::string key);
		void setLimitMode(bool state, int limit);
};

#include "Client.hpp"

#endif