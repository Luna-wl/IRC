/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:45 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/15 18:00:36 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

/* Error Replies */

#define ERR_NEEDMOREPARAMS(command)	"Error(461) " + command + " :Not enough parameters"
#define ERR_ALREADYREGISTRED		"Error(462) :You may not reregister"

#endif