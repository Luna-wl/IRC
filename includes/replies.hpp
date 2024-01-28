/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replies.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivi <csantivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:53:45 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/28 15:50:49 by csantivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLIES_HPP
# define REPLIES_HPP

/* Error Replies */
#define ERR_NOSUCHNICK(source, client, nickname)				":" + source + " 401 " + client + " :" + nickname + " :No such nick/channel"
#define ERR_NOSUCHSERVER(source, client, server_name)			":" + source + " 402 " + client + " :" + server_name + " :No such server"
#define ERR_NOSUCHCHANNEL(source, client, channel_name)			":" + source + " 403 " + client + " :" + channel_name + " :No such channel"
#define ERR_CANNOTSENDTOCHAN(source, client, channel_name)		":" + source + " 404 " + client + " :" + channel_name + " :Cannot send to channel"
#define ERR_TOOMANYCHANNELS(source, client, channel_name)		":" + source + " 405 " + client + " :" + channel_name + " :You have joined too many channels"
#define ERR_WASNOSUCHNICK(source, client, nickname)				":" + source + " 406 " + client + " :" + nickname + " :There was no such nickname"
#define ERR_TOOMANYTARGETS(source, client, target)				":" + source + " 407 " + client + " :" + target + " :Duplicate recipients. No message delivered"
#define ERR_NOORIGIN(source, client)							":" + source + " 409 " + client + " :No origin specified"
#define ERR_NORECIPIENT(source, client, command)				":" + source + " 411 " + client + " :No recipient given " + command
#define ERR_NOTEXTTOSEND(source, client)						":" + source + " 412 " + client + " :No text to send"
#define ERR_NOTOPLEVEL(source, client, mask)					":" + source + " 413 " + client + " :" + mask + " :No toplevel domain specified"
#define ERR_WILDTOPLEVEL(source, client, mask)					":" + source + " 414 " + client + " :" + mask + " :Wildcard in toplevel domain"
#define ERR_UNKNOWNCOMMAND(source, client, cmd)					":" + source + " 421 " + client + " :" + cmd + " :Unknown command"
#define ERR_NOMOTD(source, client)								":" + source + " 422 " + client + " :MOTD File is missing"
#define ERR_NOADMININFO(source, client, server)					":" + source + " 423 " + client + " :" + server + " :No administrative info available"
#define ERR_FILEERROR(source, client, fileop, file)				":" + source + " 424 " + client + " :File error doing " + fileop + " on " + file
#define ERR_NONICKNAMEGIVEN(source, client)						":" + source + " 431 " + client + " :No nickname given"
#define ERR_ERRONEUSNICKNAME(source, client, nick)				":" + source + " 432 " + client + " :" + nick + " :Erroneus nickname"
#define ERR_NICKNAMEINUSE(source, client, nick)					":" + source + " 433 " + client + " :" + nick + " :Nickname is already in use"
#define ERR_NICKCOLLISION(source, client, nick)					":" + source + " 436 " + client + " :" + nick + " :Nickname collision KILL"
#define ERR_USERNOTINCHANNEL(source, client, nick, channel)		":" + source + " 441 " + client + " :" + nick + " " + channel + " :They aren't on that channel"
#define ERR_NOTONCHANNEL(source, client, channel)				":" + source + " 442 " + client + " :" + channel + " :You're not on that channel"
#define ERR_USERONCHANNEL(source, client, user, channel)		":" + source + " 443 " + client + " :" + user + " " + channel + " :is already on channel"
#define ERR_NOLOGIN(source, client, user)						":" + source + " 444 " + client + " :" + user + " :User not logged in"
#define ERR_SUMMONDISABLED(source, client)						":" + source + " 445 " + client + " :SUMMON has been disabled"
#define ERR_USERSDISABLED(source, client)						":" + source + " 446 " + client + " :USERS has been disabled"
#define ERR_NOTREGISTERED(source, client)						":" + source + " 451 " + client + " :You have not registered\n" + "More info type 'HELP'"
#define ERR_NOTAUTHENTICATED(source, client)					":" + source + " 452 " + client + " :You have not authenticated"
#define ERR_ALREADYAUTHENTICATED(source, client)				":" + source + " 460 " + client + " :You may not reauthenticate"
#define ERR_NEEDMOREPARAMS(source, client, cmd)					":" + source + " 461 " + client + " :" + cmd + " :Not enough parameters"
#define ERR_ALREADYREGISTRED(source, client)					":" + source + " 462 " + client + " :You may not reregister"
#define ERR_NOPERMFORHOST(source, client, host)					":" + source + " 463 " + client + " :" + host + " :Your host isn't among the privileged"
#define ERR_PASSWDMISMATCH(source, client)						":" + source + " 464 " + client + " :Password incorrect"
#define ERR_YOUREBANNEDCREEP(source, client)					":" + source + " 465 " + client + " :You are banned from this server"
#define ERR_KEYSET(source, client, channel)						":" + source + " 467 " + client + " :" + channel + " :Channel key already set"
#define ERR_CHANNELISFULL(source, client, channel)				":" + source + " 471 " + client + " :" + channel + " :Cannot join channel (+l)"
#define ERR_UNKNOWNMODE(source, client, char)					":" + source + " 472 " + client + " :" + char + " :is unknown mode char to me"
#define ERR_INVITEONLYCHAN(source, client, channel)				":" + source + " 473 " + client + " :" + channel + " :Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN(source, client, channel)				":" + source + " 474 " + client + " :" + channel + " :Cannot join channel (+b)"
#define ERR_BADCHANNELKEY(source, client, channel)				":" + source + " 475 " + client + " :" + channel + " :Cannot join channel (+k)"
#define ERR_BADCHANMASK(source, client, channel)				":" + source + " 475 " + client + " :" + channel + " :Bad Channel Mask"
#define ERR_NOPRIVILEGES(source, client)						":" + source + " 481 " + client + " :Permission Denied- You're not an IRC operator"
#define ERR_CHANOPRIVSNEEDED(source, client, channel)			":" + source + " 482 " + client + " :" + channel + " :You're not channel operator"
#define ERR_CANTKILLSERVER(source, client)						":" + source + " 483 " + client + " :You cant kill a server!"
#define ERR_NOOPERHOST(source, client)							":" + source + " 491 " + client + " :No O-lines for your host"
#define ERR_UMODEUNKNOWNFLAG(source, client)					":" + source + " 501 " + client + " :Unknown MODE flag"
#define ERR_USERSDONTMATCH(source, client)						":" + source + " 502 " + client + " :Cant change mode for other users"
#define ERR_TOOMANYARGUMENTS(source, command)					":" + source + " 512 " + command + " :Too many arguments"

/* Replies */
#define RPL_AWAY(source, cmd, nick, message)				    ":"	+ source + " " + cmd + " " + nick + " :" + message
#define RPL_INVITING(source, cmd, nick, channel)			    ":" + source + " " + cmd + " " + nick + " :" + channel
#define RPL_NAMREPLY(source, cmd, symbol, channel, nick)	    ":" + source + " 353 " + cmd + " " + symbol + " " + channel + " : " + nick
#define RPL_ENDOFNAMES(source, cmd, channel)                    ":" + source + " 366 " + cmd + " " + channel + " :  End of /NAMES list."
#define RPL_CHANAWAY(source, cmd, channel, message)			    ":" + source + " " + cmd + " " + channel + " :" + message
#define RPL_INFO(source, cmd, message)						    ":" + source + " 371 " + cmd + ": " + message
#define RPL_ENDOFINFO(source, cmd)							    ":" + source + " 374 " + cmd + ": End of /INFO list."
#define RPL_YOUREOPER(source, cmd)							    ":" + source + " 381 " + cmd + ": You are now an IRC operator"

// List replies
#define RPL_LISTSTART(source)						            ":" + source + " 321 INFO Channel :Users Name"
#define RPL_LIST(source, channel, user_count, topic)		    ":" + source + " 322 INFO " + channel + " " + user_count + " :" + topic
#define RPL_LISTEND(source)							            ":" + source + " 323 INFO :End of /LIST"

// Topic replies
#define RPL_NOTOPIC(source, channel)				            ":" + source + " 331 TOPIC " + channel + " :No topic is set"
#define RPL_TOPIC(source, channel, topic)			            ":" + source + " 332 TOPIC " + channel + " :" + topic
#define RPL_TOPICWHOTIME(source, channel, nickname, time)	    ":" + source + " 333 TOPIC " + channel + " " + nickname + " " + time

// Help replies
#define RPL_HELPSTART(source, cmd)			    			    ":" + source + " 704 val " + cmd + " :Help message"
#define RPL_HELPTXT(source, cmd, message)	    			    ":" + source + " 705 val " + cmd + " :" +  message
#define RPL_ENDOFHELP(source, message)	        			    ":" + source + " " + message
#define ERR_HELPNOTFOUND(source)		        			    ":" + source + " " +  ":No help found"

#define RPL_JOINCHAN(source, channel)						    ":" + source + " join #" + channel 
#define RPL_LEAVECHAN(source, channel)						    ":" + source + " leave #" + channel

#define RPL_TIME(source, cmd, server, timestamp, time)          ":" + source + " 391 " + cmd + " : " + server + " " + timestamp + " :" + time
#define RPL_PONG(source, token)                                 ":" + source + " PONG :" + token

// welcome
#define RPL_WELCOME(source, servername, usersource)             ":" + source + " 001 :" + servername + ", " + usersource
#define RPL_YOURHOST(source, servername)                        ":" + source + " 002 :" + "Your host is " + servername
#define RPL_CREATED(source, datetime)                           ":" + source + " 003 :" + "This server was created " + datetime

#endif