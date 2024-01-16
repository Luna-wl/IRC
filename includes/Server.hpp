/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:22:30 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/16 21:40:17 by tkraikua         ###   ########.fr       */
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

#include "Color.hpp"
#include "Client.hpp"
#include "Parser.hpp"

class Parser;

class Server
{
	private:
		std::string 					_port;
		std::string 					_pass;
		int								_server_fd;
		std::vector<pollfd> 			_fds;
		std::map<const int, Client *> 	_clients;
		Parser*							_parser;
		static bool						_run;
	public:
		
		Server( const std::string & port, const std::string & pass );
		~Server( void );

		int start( void );
		void server_loop( void );
		void create_connection( void );
		void receive_message(int fd);
		// void receive_message(std::vector<pollfd>::iterator it);
		void add_client(int client_fd, std::string hostname);
		void add_pollfd(int fd);

		static void set_state(bool state);

		// getter
		std::string getPass();
		std::map<const int, Client *> 	&getClient();
};

#endif
