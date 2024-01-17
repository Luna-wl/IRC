/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:16:08 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/18 01:46:59 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include <iostream>
# include <map>

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

		// getter
		std::string getName();
};

#include "Client.hpp"

#endif