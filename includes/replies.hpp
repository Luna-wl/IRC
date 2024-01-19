/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:45 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/19 23:29:28 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

/* Error Replies */

#define ERR_NOSUCHNICK(source, cmd, nickname)			    ":" + source + " " + cmd + " 401 " + nickname + " :No such nick/channel"
#define ERR_NOSUCHSERVER(source, cmd, server_name)		    ":" + source + " " + cmd + " 402 " + server_name + " :No such server"
#define ERR_NOSUCHCHANNEL(source, cmd, channel_name)	    ":" + source + " " + cmd + " 403 " + channel_name + " :No such channel"
#define ERR_CANNOTSENDTOCHAN(source, cmd, channel_name)	    ":" + source + " " + cmd + " 404 " + channel_name + " :Cannot send to channel"
#define ERR_TOOMANYCHANNELS(source, cmd, channel_name)	    ":" + source + " " + cmd + " 405 " + channel_name + " :You have joined too many channels"
#define ERR_WASNOSUCHNICK(source, cmd, nickname)		    ":" + source + " " + cmd + " 406 " + nickname + " :There was no such nickname"
#define ERR_TOOMANYTARGETS(source, cmd, target)			    ":" + source + " " + cmd + " 407 " + target + " :Duplicate recipients. No message delivered"
#define ERR_NOORIGIN(source, cmd)						    ":" + source + " " + cmd + " 409 :No origin specified"
#define ERR_NORECIPIENT(source, cmd, command)			    ":" + source + " " + cmd + " 411 :No recipient given " + command
#define ERR_NOTEXTTOSEND(source, cmd)					    ":" + source + " " + cmd + " 412 :No text to send"
#define ERR_NOTOPLEVEL(source, cmd, mask)				    ":" + source + " " + cmd + " 413 " + mask + " :No toplevel domain specified"
#define ERR_WILDTOPLEVEL(source, cmd, mask)				    ":" + source + " " + cmd + " 414 " + mask + " :Wildcard in toplevel domain"
#define ERR_UNKNOWNCOMMAND(source, cmd)		    			":" + source + " " + cmd + " 421 " + cmd + " :Unknown command"
#define ERR_NOMOTD(source, cmd)							    ":" + source + " " + cmd + " 422 :MOTD File is missing"
#define ERR_NOADMININFO(source, cmd, server)			    ":" + source + " " + cmd + " 423 " + server + " :No administrative info available"
#define ERR_FILEERROR(source, cmd, fileop, file)		    ":" + source + " " + cmd + " 424 :File error doing " + fileop + " on " + file
#define ERR_NONICKNAMEGIVEN(source, cmd)				    ":" + source + " " + cmd + " 431 :No nickname given"
#define ERR_ERRONEUSNICKNAME(source, cmd, nick)			    ":" + source + " " + cmd + " 432 " + nick + " :Erroneus nickname"
#define ERR_NICKNAMEINUSE(source, cmd, nick)			    ":" + source + " " + cmd + " 433 " + nick + " :Nickname is already in use"
#define ERR_NICKCOLLISION(source, cmd, nick)			    ":" + source + " " + cmd + " 436 " + nick + " :Nickname collision KILL"
#define ERR_USERNOTINCHANNEL(source, cmd, nick, channel)    ":" + source + " " + cmd + " 441 " + nick + " " + channel + " :They aren't on that channel"
#define ERR_NOTONCHANNEL(source, cmd, channel)			    ":" + source + " " + cmd + " 442 " + channel + " :You're not on that channel"
#define ERR_USERONCHANNEL(source, cmd, user, channel)	    ":" + source + " " + cmd + " 443 " + user + " " + channel + " :is already on channel"
#define ERR_NOLOGIN(source, cmd, user)					    ":" + source + " " + cmd + " 444 " + user + " :User not logged in"
#define ERR_SUMMONDISABLED(source, cmd)					    ":" + source + " " + cmd + " 445 :SUMMON has been disabled"
#define ERR_USERSDISABLED(source, cmd)					    ":" + source + " " + cmd + " 446 :USERS has been disabled"
#define ERR_NOTREGISTERED(source, cmd)					    ":" + source + " " + cmd + " 451 :You have not registered"
#define ERR_NOTAUTHENTICATED(source, cmd)				    ":" + source + " " + cmd + " 452 :You have not authenticated"
#define ERR_ALREADYAUTHENTICATED(source, cmd)			    ":" + source + " " + cmd + " 460 :You may not reauthenticate"
#define ERR_NEEDMOREPARAMS(source, cmd)         			":" + source + " " + cmd + " 461 " + cmd + " :Not enough parameters"
#define ERR_ALREADYREGISTRED(source, cmd)				    ":" + source + " " + cmd + " 462 :You may not reregister"
#define ERR_NOPERMFORHOST(source, cmd, host)				":" + source + " " + cmd + " 463 " + host + " :Your host isn't among the privileged"
#define ERR_PASSWDMISMATCH(source, cmd)					    ":" + source + " " + cmd + " 464 :Password incorrect"
#define ERR_YOUREBANNEDCREEP(source, cmd)		    		":" + source + " " + cmd + " 465 :You are banned from this server"
#define ERR_KEYSET(source, cmd, channel)					":" + source + " " + cmd + " 467 " + channel + " :Channel key already set"
#define ERR_CHANNELISFULL(source, cmd, channel)		    	":" + source + " " + cmd + " 471 " + channel + " :Cannot join channel (+l)"
#define ERR_UNKNOWNMODE(source, cmd, char)					":" + source + " " + cmd + " 472 " + char + " :is unknown mode char to me"
#define ERR_INVITEONLYCHAN(source, cmd, channel)			":" + source + " " + cmd + " 473 " + channel + " :Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN(source, cmd, channel)			":" + source + " " + cmd + " 474 " + channel + " :Cannot join channel (+b)"
#define ERR_BADCHANNELKEY(source, cmd, channel)		    	":" + source + " " + cmd + " 475 " + channel + " :Cannot join channel (+k)"
#define ERR_NOPRIVILEGES(source, cmd)				    	":" + source + " " + cmd + " 481 :Permission Denied- You're not an IRC operator"
#define ERR_CHANOPRIVSNEEDED(source, cmd, channel)	    	":" + source + " " + cmd + " 482 " + channel + " :You're not channel operator"
#define ERR_CANTKILLSERVER(source, cmd)				    	":" + source + " " + cmd + " 483 :You cant kill a server!"
#define ERR_NOOPERHOST(source, cmd)					    	":" + source + " " + cmd + " 491 :No O-lines for your host"
#define ERR_UMODEUNKNOWNFLAG(source, cmd)			    	":" + source + " " + cmd + " 501 :Unknown MODE flag"
#define ERR_USERSDONTMATCH(source, cmd)				    	":" + source + " " + cmd + " 502 :Cant change mode for other users"

/* Replies */
#define RPL_AWAY(source, cmd, nick, message)				":"	+ source + " " + cmd + " " + nick + " :" + message
#define RPL_NAMREPLY(source, cmd, symbol, channel, nick)	":" + source + " " + cmd + " " + symbol + " " + channel + " : 353 : " + nick
#define RPL_ENDOFNAMES(source, cmd, channel)                ":" + source + " " + cmd + " " + channel + "  : 366 : End of /NAMES list."
#define RPL_CHANAWAY(source, cmd, channel, message)			":" + source + " " + cmd + " " + channel + " :" + message
#define RPL_INFO(source, cmd, message)						":" + source + " " + cmd + ": 371 :" + message
#define RPL_ENDOFINFO(source, cmd)							":" + source + " " + cmd + ": 374 :End of /INFO list."
#define RPL_YOUREOPER(source, cmd)							":" + source + " " + cmd + ": 381 :You are now an IRC operator"

#define RPL_JOINCHAN(source, channel)						":" + source + " join #" + channel 
#define RPL_LEAVECHAN(source, channel)						":" + source + " leave #" + channel

#endif