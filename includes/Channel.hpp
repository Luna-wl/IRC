/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:08 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 01:15:21 by csantivimol      ###   ########.fr       */
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
		std::vector<Client *>	_clients;
		std::string				_topic;
		std::string				_key;
	public:
		Channel(std::string name, std::string key);
		~Channel();

		void addClient(Client * clienet);
		void send_message(Client * client, std::string message);

		// getter
		std::string getName();
};

#include "Client.hpp"

#endif