/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantivimol <csantivimol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:23:58 by tkraikua          #+#    #+#             */
/*   Updated: 2024/01/07 22:28:29 by csantivimol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void server_loop(int sockfd);

Server::Server( const std::string & port, const std::string & pass )
{
	// std::cout << "Server constructor called." << std::endl;
	this->port = port;
	this->pass = pass;
}

Server::~Server( void )
{
	// std::cout << "Server deconstructure called." << std::endl;
}

void Server::start( void )
{
	// สร้างซ็อกเก็ต TCP
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "Error creating socket" << std::endl;
		exit(1);
	}

	// ตั้งค่าตัวเลือกซ็อกเก็ต
	int optval = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	// ผูกซ็อกเก็ตกับที่อยู่
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(stoi(port));
	addr.sin_addr.s_addr = INADDR_ANY;
	std::cout << "starting server\n"; //DEBUG
	std::cout << "Port : " << this->port << std::endl; //DEBUG
	std::cout << "Pass : " << this->pass << std::endl; //DEBUG
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cerr << "Error binding socket" << std::endl;
		exit(1);
	}

	listen(sockfd, 2);
	// next step is listen for connection
	server_loop(sockfd);
}

void server_loop(int sockfd)
{
    std::vector<pollfd> fds;

    pollfd server_poll_fd;
    server_poll_fd.fd = sockfd;
    server_poll_fd.events = POLLIN;

    fds.push_back(server_poll_fd);
    std::cout << "socketfd is " << fds[0].fd << "\n";

    bool run = true;
    char buffer[1024];
	std::cout << "------------------------------------" << std::endl; //DEBUG
    while (run)
    {
        std::cout << "waiting for poll . . .\n"; // DEBUG
        poll(&fds[0], fds.size(), -1);
        std::cout << "Has some signal from poll! ---size[" << fds.size() << "]\n"; // DEBUG
        for (int i = 0; i < fds.size(); i++)
        {
            if (fds[i].revents & POLLIN)
            {
				std::cout << "[Poll IN!]\n";
                if (fds[i].fd == sockfd)
                {
                    pollfd client_poll_fd;

                    struct sockaddr_in client_addr;
                    socklen_t client_addr_len = sizeof(client_addr);
                    client_poll_fd.fd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
                    if (client_poll_fd.fd < 0)
                    {
                        std::cerr << "Error accepting connection" << std::endl;
                        exit(1);
                    }
                    fds.push_back(client_poll_fd);
                    std::cout << "Connected from : " << client_poll_fd.fd << std::endl;
                }
                else
                {
					std::cout << "caught data ! ! ! \n";
                    int nread = recv(fds[i].fd, buffer, sizeof(buffer), 0);
                    /* Parser (cut after \n character) */
                    std::string text(buffer);
                    int found = text.find("\n");
                    if (found != std::string::npos)
                        text = text.substr(0, found);
                    /* detect information */
                    std::cout << "receive : " << text << std::endl;
                    if (text == "stop")
                        run = false;

                    /* clear buffer */
                    memset(buffer, 0, sizeof(buffer));

                    if (nread < 0)
                    {
                        std::cerr << "Error receiving data" << std::endl;
                        exit(1);
                    }
                    // ส่งข้อมูลกลับ
                    send(fds[i].fd, buffer, nread, 0);
                }
            }
            else if (fds[i].revents & POLLOUT)
            {
				std::cout << "[Poll Out!]\n";
            }
            else if (fds[i].revents & POLLERR)
            {
				std::cout << "[Poll Error!]\n";
            }
        }
    }

    for (int i = 0; i < fds.size(); i++)
    {
        close(fds[i].fd);
    }
}



// void server_loop(int sockfd) // original version
// {
// 	//	ฟังการเชื่อมต่อ
// 	std::cout << "waiting for connection . . .\n"; //DEBUG
// 	listen(sockfd, 1);

// 	// รับการเชื่อมต่อ
// 	struct sockaddr_in client_addr;
// 	socklen_t client_addr_len = sizeof(client_addr);
// 	int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
// 	if (clientfd < 0) {
// 		std::cerr << "Error accepting connection" << std::endl;
// 		exit(1);
// 	}
// 	std::cout << "Connected from : " << clientfd << std::endl;

// 	//----------------------------
// 	// รับข้อมูล
// 	char buffer[1024];
// 	bool run = true;
// 	while (run)
// 	{
// 		int nread = recv(clientfd, buffer, sizeof(buffer), 0);

// 		/* Parser (cut after \n character) */
// 		std::string text(buffer);
// 		int found = text.find("\n");
// 		if (found != std::string::npos)
// 			text = text.substr(0, found);
// 		/* detect information */
// 		std::cout << "receive : " << text << std::endl;
// 		if (text == "stop")
// 			run = false;
// 		/* clear buffer */
// 		bzero(buffer, strlen(buffer));
	
// 		if (nread < 0) {
// 			std::cerr << "Error receiving data" << std::endl;
// 			exit(1);
// 		}

// 		// ส่งข้อมูลกลับ
// 		send(clientfd, buffer, nread, 0);
// 	}
// 	//----------------------------

// 	// ปิดซ็อกเก็ต
// 	close(clientfd);
// 	close(sockfd);
// }
