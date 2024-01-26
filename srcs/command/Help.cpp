/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:25 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/26 16:25:29 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Help::Help(Server * srv) : Command(srv) {}

Help::~Help() {}

void Help::execute(Client * client, std::vector<std::string> &args)
{
	if (args.size() == 1) {
		client->recieveMessage(RPL_HELPSTART(_srv->getName(), args[0]));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "If you not register, you can use these commands:"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PASS <server's password>: enter password to regist in the server"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> NICK <nickname>: set your nickname"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> USER <username> 0 * <realname>: set your username"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], ""));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "If you register, you can use these commands:"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> INFO: show server information"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> INVITE <nickname> <channel>: invite a user to a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> JOIN <channel>: join a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> KICK <channel> <nickname>: kick a user from a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> LIST <channel>: list all channels"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> MODE <channel> <mode>: set a mode for a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "  -i: Set/remove Invite-only channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "  -t: Set/remove the restrictions of the TOPIC command to channel operators"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "  -k: Set/remove the channel key (password"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "  -o: Give/take channel operator privilege"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "  -l: Set/remove the user limit to channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> NAMES <channel>: list all users in a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> NOTICE <nickname> <message>: send a notice to a user"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> OPER <name> <password>: to obtain IRC operator privileges"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PART <channel>: leave a channel"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PASS <password>: set your password"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PRIVMSG <receiver> <message>: send a message to a receiver"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PING <server>: ping a server"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> PONG <server>: pong a server"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> QUIT: disconnect from the server"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> TIME <server>: show the time of a server"));
		client->recieveMessage(RPL_HELPTXT(_srv->getName(), args[0], "> TOPIC <channel> <topic>: set a topic for a channel"));
		return ;
	}
	client->recieveMessage(ERR_TOOMANYARGUMENTS(_srv->getName(), "HELP"));
}