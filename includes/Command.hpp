/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:12:18 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:45 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <vector>
# include <sys/socket.h>

# include "Client.hpp"

class Command
{
	private:
		// std::vector<string>    _args;
		// std::string            _cmd;
		// std::string            _prefix;
		// bool                   _valid;
	public:
		Command(/* args */);
		virtual ~Command();

		virtual void execute(Client * client, std::vector<std::string> &args) = 0;
};

class Nick : public Command
{
	public:
		Nick();
		~Nick();

		void execute(Client * client, std::vector<std::string> &args);
};

#endif