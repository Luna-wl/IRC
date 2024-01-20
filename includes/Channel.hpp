/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:08 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 13:19:59 by wluedara         ###   ########.fr       */
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

		int getClietNum();
		std::string getTopic();
};

#include "Client.hpp"

#endif