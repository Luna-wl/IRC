/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:50:51 by csantivimol       #+#    #+#             */
/*   Updated: 2024/01/20 01:27:18 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <iostream>
# include <sys/socket.h>

# include "Channel.hpp"

# define CHANLIMIT 5

class Client
{
	private:
		int 			_client_fd;
		std::string		_nickname;
		std::string		_hostname;
		std::string		_servername;
		std::string		_fullname;
		std::string		_username;

		bool			_auth;
		bool			_regist;
		bool			_op; // operator or regular user
		// int				_socket; // Socket descriptor for the user's connection

		std::map<std::string, Channel *> _channels;

	public:
		Client( const int &client_fd, std::string hostname );
		~Client( void );

		void receive_message(std::string str);
		void send_error(std::string str);
		void send_debug(std::string str);

		std::string source();

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

		bool isAuth();
		void setAuth(bool state);
		bool isRegist();
		void setRegist(bool state);
		bool isOper();
		void setOper(bool state);

		void join(Channel * channel);
		void leave(Channel * channel);
		Channel * getChannel(std::string channel_name);
		std::map<std::string, Channel *> getAllChannel();
		int getChannelSize();
};

#endif