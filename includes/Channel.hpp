/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:08 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 01:44:02 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <map>

# include "replies.hpp"

class Client;

class Channel
{
	private:
		std::string				_name;
		std::vector<Client *>	_members;
		std::string				_topic;
		std::string				_key;
		int						_userLimit;
		/* MODES */
		bool	_i; // Invite-only
		bool	_t; // restrict TOPIC
		bool	_k; // set key
		bool	_o; // channel operator privilege
		bool	_l; // user limit
	public:
		Channel(std::string name, std::string key);
		~Channel();

		void addClient(Client * clienet);
		void send_message(Client * client, std::string message);

		// getter
		std::string getName();
		std::string getKey();

		bool isFull();
		
		/* get Modes */
		bool isInviteMode();
		bool isTopicMode();
		bool isKeyMode();
		bool isOperMode();
		bool isLimitMode();
};

#include "Client.hpp"

#endif