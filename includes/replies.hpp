/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkraikua <tkraikua@student.42.th>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:45 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/15 22:51:12 by tkraikua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

/* Error Replies */

#define ERR_NOSUCHNICK(nickname)			"Error(401) " + nickname + " :No such nick/channel"
#define ERR_NOSUCHSERVER(server_name)		"Error(402) " + server_name + " :No such server"
#define ERR_NOSUCHCHANNEL(channel_name)		"Error(403) " + channel_name + " :No such channel"
#define ERR_CANNOTSENDTOCHAN(channel_name)	"Error(404) " + channel_name + " :Cannot send to channel"
#define ERR_TOOMANYCHANNELS(channel_name)	"Error(405) " + channel_name + " :You have joined too many channels"
#define ERR_WASNOSUCHNICK(nickname)			"Error(406) " + nickname + " :There was no such nickname"
#define ERR_TOOMANYTARGETS(target)			"Error(407) " + target + " :Duplicate recipients. No message delivered"
#define ERR_NOORIGIN						"Error(409) :No origin specified"
#define ERR_NORECIPIENT(command)			"Error(411) :No recipient given " + command
#define ERR_NOTEXTTOSEND					"Error(412) :No text to send"
#define ERR_NOTOPLEVEL(mask)				"Error(413) " + mask + " :No toplevel domain specified"
#define ERR_WILDTOPLEVEL(mask)				"Error(414) " + mask + " :Wildcard in toplevel domain"
#define ERR_UNKNOWNCOMMAND(command)			"Error(421) " + command + " :Unknown command"
#define ERR_NOMOTD							"Error(422) :MOTD File is missing"
#define ERR_NOADMININFO(server)				"Error(423) " + server + " :No administrative info available"
#define ERR_FILEERROR(fileop, file)			"Error(424) :File error doing " + fileop + " on " + file
#define ERR_NONICKNAMEGIVEN					"Error(431) :No nickname given"
#define ERR_ERRONEUSNICKNAME(nick)			"Error(432) " + nick + " :Erroneus nickname"
#define ERR_NICKNAMEINUSE(nick)				"Error(433) " + nick + " :Nickname is already in use"
#define ERR_NICKCOLLISION(nick)				"Error(436) " + nick + " :Nickname collision KILL"
#define ERR_USERNOTINCHANNEL(nick, channel)	"Error(441) " + nick + " " + channel + " :They aren't on that channel"
#define ERR_NOTONCHANNEL(channel)			"Error(442) " + channel + " :You're not on that channel"
#define ERR_USERONCHANNEL(user, channel)	"Error(443) " + user + " " + channel + " :is already on channel"
#define ERR_NOLOGIN(user)					"Error(444) " + user + " :User not logged in"
#define ERR_SUMMONDISABLED					"Error(445) :SUMMON has been disabled"
#define ERR_USERSDISABLED					"Error(446) :USERS has been disabled"
#define ERR_NOTREGISTERED					"Error(451) :You have not registered"
#define ERR_NEEDMOREPARAMS(command)			"Error(461) " + command + " :Not enough parameters"
#define ERR_ALREADYREGISTRED				"Error(462) :You may not reregister"
#define ERR_NOPERMFORHOST(host)				"Error(463) " + host + " :Your host isn't among the privileged"
#define ERR_PASSWDMISMATCH					"Error(464) :Password incorrect"
#define ERR_YOUREBANNEDCREEP				"Error(465) :You are banned from this server"
#define ERR_KEYSET(channel)					"Error(467) " + channel + " :Channel key already set"
#define ERR_CHANNELISFULL(channel)			"Error(471) " + channel + " :Cannot join channel (+l)"
#define ERR_UNKNOWNMODE(char)				"Error(472) " + char + " :is unknown mode char to me"
#define ERR_INVITEONLYCHAN(channel)			"Error(473) " + channel + " :Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN(channel)			"Error(474) " + channel + " :Cannot join channel (+b)"
#define ERR_BADCHANNELKEY(channel)			"Error(475) " + channel + " :Cannot join channel (+k)"
#define ERR_NOPRIVILEGES					"Error(481) :Permission Denied- You're not an IRC operator"
#define ERR_CHANOPRIVSNEEDED(channel)		"Error(482) " + channel + " :You're not channel operator"
#define ERR_CANTKILLSERVER					"Error(483) :You cant kill a server!"
#define ERR_NOOPERHOST						"Error(491) :No O-lines for your host"
#define ERR_UMODEUNKNOWNFLAG				"Error(501) :Unknown MODE flag"
#define ERR_USERSDONTMATCH					"Error(502) :Cant change mode for other users"

#endif