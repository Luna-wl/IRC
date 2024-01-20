/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:45 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/20 13:51:37 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

/* Error Replies */

#define ERR_NOSUCHNICK(source, nickname)			":" + source + " :Error(401) " + nickname + " :No such nick/channel"
#define ERR_NOSUCHSERVER(source, server_name)		":" + source + " :Error(402) " + server_name + " :No such server"
#define ERR_NOSUCHCHANNEL(source, channel_name)		":" + source + " :Error(403) " + channel_name + " :No such channel"
#define ERR_CANNOTSENDTOCHAN(source, channel_name)	":" + source + " :Error(404) " + channel_name + " :Cannot send to channel"
#define ERR_TOOMANYCHANNELS(source, channel_name)	":" + source + " :Error(405) " + channel_name + " :You have joined too many channels"
#define ERR_WASNOSUCHNICK(source, nickname)			":" + source + " :Error(406) " + nickname + " :There was no such nickname"
#define ERR_TOOMANYTARGETS(source, target)			":" + source + " :Error(407) " + target + " :Duplicate recipients. No message delivered"
#define ERR_NOORIGIN(source)						":" + source + " :Error(409) :No origin specified"
#define ERR_NORECIPIENT(source, command)			":" + source + " :Error(411) :No recipient given " + command
#define ERR_NOTEXTTOSEND(source)					":" + source + " :Error(412) :No text to send"
#define ERR_NOTOPLEVEL(source, mask)				":" + source + " :Error(413) " + mask + " :No toplevel domain specified"
#define ERR_WILDTOPLEVEL(source, mask)				":" + source + " :Error(414) " + mask + " :Wildcard in toplevel domain"
#define ERR_UNKNOWNCOMMAND(source, command)			":" + source + " :Error(421) " + command + " :Unknown command"
#define ERR_NOMOTD(source)							":" + source + " :Error(422) :MOTD File is missing"
#define ERR_NOADMININFO(source, server)				":" + source + " :Error(423) " + server + " :No administrative info available"
#define ERR_FILEERROR(source, fileop, file)			":" + source + " :Error(424) :File error doing " + fileop + " on " + file
#define ERR_NONICKNAMEGIVEN(source)					":" + source + " :Error(431) :No nickname given"
#define ERR_ERRONEUSNICKNAME(source, nick)			":" + source + " :Error(432) " + nick + " :Erroneus nickname"
#define ERR_NICKNAMEINUSE(source, nick)				":" + source + " :Error(433) " + nick + " :Nickname is already in use"
#define ERR_NICKCOLLISION(source, nick)				":" + source + " :Error(436) " + nick + " :Nickname collision KILL"
#define ERR_USERNOTINCHANNEL(source, nick, channel)	":" + source + " :Error(441) " + nick + " " + channel + " :They aren't on that channel"
#define ERR_NOTONCHANNEL(source, channel)			":" + source + " :Error(442) " + channel + " :You're not on that channel"
#define ERR_USERONCHANNEL(source, user, channel)	":" + source + " :Error(443) " + user + " " + channel + " :is already on channel"
#define ERR_NOLOGIN(source, user)					":" + source + " :Error(444) " + user + " :User not logged in"
#define ERR_SUMMONDISABLED(source)					":" + source + " :Error(445) :SUMMON has been disabled"
#define ERR_USERSDISABLED(source)					":" + source + " :Error(446) :USERS has been disabled"
#define ERR_NOTREGISTERED(source)					":" + source + " :Error(451) :You have not registered"
#define ERR_NOTAUTHENTICATED(source)				":" + source + " :Error(452) :You have not authenticated"
#define ERR_ALREADYAUTHENTICATED(source)			":" + source + " :Error(460) :You may not reauthenticate"
#define ERR_NEEDMOREPARAMS(source, command)			":" + source + " :Error(461) " + command + " :Not enough parameters"
#define ERR_ALREADYREGISTRED(source)				":" + source + " :Error(462) :You may not reregister"
#define ERR_NOPERMFORHOST(source, host)				":" + source + " :Error(463) " + host + " :Your host isn't among the privileged"
#define ERR_PASSWDMISMATCH(source)					":" + source + " :Error(464) :Password incorrect"
#define ERR_YOUREBANNEDCREEP(source)				":" + source + " :Error(465) :You are banned from this server"
#define ERR_KEYSET(source, channel)					":" + source + " :Error(467) " + channel + " :Channel key already set"
#define ERR_CHANNELISFULL(source, channel)			":" + source + " :Error(471) " + channel + " :Cannot join channel (+l)"
#define ERR_UNKNOWNMODE(source, char)				":" + source + " :Error(472) " + char + " :is unknown mode char to me"
#define ERR_INVITEONLYCHAN(source, channel)			":" + source + " :Error(473) " + channel + " :Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN(source, channel)			":" + source + " :Error(474) " + channel + " :Cannot join channel (+b)"
#define ERR_BADCHANNELKEY(source, channel)			":" + source + " :Error(475) " + channel + " :Cannot join channel (+k)"
#define ERR_NOPRIVILEGES(source)					":" + source + " :Error(481) :Permission Denied- You're not an IRC operator"
#define ERR_CHANOPRIVSNEEDED(source, channel)		":" + source + " :Error(482) " + channel + " :You're not channel operator"
#define ERR_CANTKILLSERVER(source)					":" + source + " :Error(483) :You cant kill a server!"
#define ERR_NOOPERHOST(source)						":" + source + " :Error(491) :No O-lines for your host"
#define ERR_UMODEUNKNOWNFLAG(source)				":" + source + " :Error(501) :Unknown MODE flag"
#define ERR_USERSDONTMATCH(source)					":" + source + " :Error(502) :Cant change mode for other users"
#define ERR_TOOMANYARGUMENTS(source, command)		":" + source + " :Error(512) " + command + " :Too many arguments"

/* Replies */
#define RPL_AWAY(source, nick, message)				":"	+ source + " " + nick + " :" + message
#define RPL_CHANAWAY(source, channel, message)		":" + source + " " + channel + " :" + message

// List replies
#define RPL_LISTSTART(source)						":" + source + " :Channel :Users  Name"
#define RPL_LIST(channel, user_count, topic)		" CHANNEL NAME: " + channel + "\n USER NUMBER: " + user_count + "\n TOPIC:" + topic + "\n=========="
#define RPL_LISTEND(source)							":" + source + " :End of /LIST"

#endif