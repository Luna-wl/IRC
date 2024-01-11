/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:51 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/11 23:14:14 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>

class Client
{
	private:
		int _client_fd;
		// std::string             _nickname;
		// std::string             _fullname;
		// std::string             _username;

		// bool                    _regist;
		// int                     _socket; // Socket descriptor for the user's connection
		
		// vector/map/list         _currentChannel;
	public:
		Client( const int &client_fd);
		~Client( void );
		int getFd();
};

#endif