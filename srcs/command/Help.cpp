/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:25 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/21 22:56:36 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Help::Help(Server * srv) : Command(srv) {}

Help::~Help() {}

void Help::execute(Client * client, std::vector<std::string> &args)
{
	int num = args.size();
	if (num == 2) {
		// helpCmd(client, args[1]);
	}
	else if (num == 1) {
		client->receive_message("If you not register, you can use these commands:");
		client->receive_message("NICK <nickname>: set your nickname");
		client->receive_message("USER <username> 0 * <realname>: set your username");
		
		client->receive_message("If you register, you can use these commands:");
		client->receive_message("JOIN <channel>: join a channel");
		client->receive_message("PART <channel>: leave a channel");
		client->receive_message("PRIVMSG <receiver> <message>: send a message to a receiver");
		client->receive_message("NAMES <channel>: list all users in a channel");
		client->receive_message("LIST <channel>: list all channels");
		client->receive_message("TOPIC <channel> <topic>: set a topic for a channel");
		client->receive_message("QUIT: disconnect from the server");
		return ;
	}
	else
		client->receive_message(ERR_TOOMANYARGUMENTS(client->getUsername(), "HELP"));
}