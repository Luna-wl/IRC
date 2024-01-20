/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Help.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 01:35:25 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/21 01:35:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Help::Help(Server * srv) : Command(srv) {}

Help::~Help() {}

void Help::execute(Client * client, std::vector<std::string> &args)
{
	(void)args;
	client->reply(RPL_HELPSTART, client->getName());
	client->reply(RPL_HELPTXT, "This is the help message");
	client->reply(RPL_ENDOFHELP, "End of HELP info");
}