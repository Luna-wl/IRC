/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:24 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/19 22:40:20 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Invite::Invite(Server * srv) : Command(srv) {}

Invite::~Invite() {}

void Invite::execute(Client * client, std::vector<std::string> &args) {
	(void)client;
	(void)args;
}