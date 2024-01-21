/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:25 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/22 00:19:45 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Help::Help(Server * srv) : Command(srv) {}

Help::~Help() {}

void Help::execute(Client * client, std::vector<std::string> &args)
{
	if (args.size() == 1) {
		std::string message = "\nIf you not register, you can use these commands:\n";
		message += "> NICK <nickname>: set your nickname\n";
		message += "> USER <username> 0 * <realname>: set your username\n\n";
		
		message += "If you register, you can use these commands:\n";
		message += "> INFO: show server information\n";
		message += "> INVITE <nickname> <channel>: invite a user to a channel\n";
		message += "> JOIN <channel>: join a channel\n";
		message += "> KICK <channel> <nickname>: kick a user from a channel\n";
		message += "> LIST <channel>: list all channels\n";
		message += "> MODE <channel> <mode>: set a mode for a channel\n";
		message += "  -i: Set/remove Invite-only channel\n";
		message += "  -t: Set/remove the restrictions of the TOPIC command to channel operators\n";
		message += "  -k: Set/remove the channel key (password\n";
		message += "  -o: Give/take channel operator privilege\n";
		message += "  -l: Set/remove the user limit to channel\n";
		message += "> NAMES <channel>: list all users in a channel\n";
		message += "> NOTICE <nickname> <message>: send a notice to a user\n";
		message += "> OPER <name> <password>: to obtain IRC operator privileges\n";
		message += "> PART <channel>: leave a channel\n";
		message += "> PASS <password>: set your password\n";
		message += "> PRIVMSG <receiver> <message>: send a message to a receiver\n";
		message += "> PING <server>: ping a server\n";
		message += "> PONG <server>: pong a server\n\n";
		message += "> QUIT: disconnect from the server\n";
		message += "> TIME <server>: show the time of a server\n";
		message += "> TOPIC <channel> <topic>: set a topic for a channel\n";
		client->receive_message(message);
		return ;
	}
	client->receive_message(ERR_TOOMANYARGUMENTS(_srv->getName(), "HELP"));
}