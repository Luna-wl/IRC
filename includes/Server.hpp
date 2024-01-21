/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:22:30 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 01:26:25 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <map>
#include <netdb.h>
#include <arpa/inet.h>
#include <ctime>
#include <iomanip>

#include "Color.hpp"
#include "replies.hpp"

class Channel;
class Client;
class Parser;

class Server
{
	private:
		std::string							_name;
		std::string 						_port;
		std::string 						_pass;
		int									_server_fd;
		std::vector<pollfd> 				_fds;
		std::map<std::string, Channel *>	_channels;
		std::map<const int, Client *> 		_clients;
		Parser*								_parser;
		static bool							_run;
	public:
		
		Server( const std::string & port, const std::string & pass );
		~Server( void );

		int start( void );
		void server_loop( void );
		void create_connection( void );
		void receive_message(int fd);
		void add_client(int client_fd, std::string hostname);
		void add_pollfd(int fd);
		std::string time(int format);
		void clientDisconnect(int fd);

		static void set_state(bool state);

		// getter
		std::string getName();
		std::string getPass();
		std::string getPort();
		int getChannelNum();
		int getClientNum();

		std::map<const int, Client *> 	&getClient();
		Client * get_client(std::string client_nickname);

		void addChannel(Channel * channel);
		void removeChannel(std::string channel_name);
		Channel * getChannel(std::string channel_name);
		bool isChanExist(std::string channel_name);

		std::map<std::string, Channel*>& getChannels();
};

#include "Channel.hpp"
#include "Client.hpp"
#include "Parser.hpp"

#endif
