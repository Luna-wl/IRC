/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:00:27 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/24 22:48:26 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/Command.hpp"

Command::Command(Server * srv) : _srv(srv) {}

Command::~Command() {}

std::vector<std::string> commaSeperator(std::string arg)
{
	std::vector<std::string> ret;
	size_t pos = 0;
	std::string tmp; 
	while ((pos = arg.find(",")) != std::string::npos)
	{
		tmp = arg.substr(0, pos);
        if (!tmp.empty())
            ret.push_back(tmp);
        arg.erase(0, pos + 1);
	}
	tmp = arg.substr(0, pos);
	if (!tmp.empty())
		ret.push_back(tmp);
	return (ret);
}