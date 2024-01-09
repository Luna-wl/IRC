/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:22:30 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/09 15:39:19 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <poll.h>
#include <Client.hpp>
#include <map>

class Server
{
	private:
		std::string _port;
		std::string _pass;
		int			_server_fd;
		std::map<const int, Client> _clients;
		bool		_run;
	public:
		Server( const std::string & port, const std::string & pass );
		~Server( void );

		void start( void );
		void server_loop( void );
		void create_connection( std::vector<pollfd> &fds );
		void receive_message( std::vector<pollfd> &fds , std::vector<pollfd>::iterator it);
};

#endif
