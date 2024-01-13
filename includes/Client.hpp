/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:51 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/14 01:24:15 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>
# include <sys/socket.h>

class Client
{
	private:
		int 			_client_fd;
		std::string		_nickname;
		std::string		_hostname;
		std::string		_servername;
		std::string		_fullname;
		std::string		_username;

		// bool			_regist;
		// int				_socket; // Socket descriptor for the user's connection
		
		// vector/map/list	_currentChannel;
	public:
		Client( const int &client_fd);
		~Client( void );

		void receive_message(std::string str);

		// getter
		std::string getNickname();
		std::string getHostname();
		std::string getServername();
		std::string getFullname();
		std::string getUsername();
		int getFd();
		
		// setter
		void setNickname(std::string name);
		void setHostname(std::string name);
		void setServername(std::string name);
		void setFullname(std::string name);
		void setUsername(std::string name);
};

#endif