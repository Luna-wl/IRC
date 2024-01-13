/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:16:57 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/14 01:26:53 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

Nick::Nick()
{
	
}

Nick::~Nick()
{

}

void Nick::execute(Client * client, std::vector<std::string> &args)
{
	std::cout << "NICK executed" << std::endl;

	if (args[1].empty()) {
		std::cerr << "TOO FEW ARGUMENTS" << std::endl;
		client->receive_message("TOO FEW ARGUMENTS");
	} else {
		client->setNickname(args[1]);
	}
}