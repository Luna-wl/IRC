/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:33:40 by wluedara          #+#    #+#             */
/*   Updated: 2024/01/19 22:40:08 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Kick::Kick(Server * srv) : Command(srv) {}

Kick::~Kick() {}

void Kick::execute(Client * client, std::vector<std::string> &args) {
	(void)client;
	(void)args;
}