#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
	// สร้างซ็อกเก็ต TCP
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		std::cerr << "Error creating socket" << std::endl;
		return 1;
	}

	// ตั้งค่าตัวเลือกซ็อกเก็ต
	int optval = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

	// ผูกซ็อกเก็ตกับที่อยู่
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		std::cerr << "Error binding socket" << std::endl;
		return 1;
	}

	// ฟังการเชื่อมต่อ
	listen(sockfd, 1);

	// รับการเชื่อมต่อ
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);
	int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
	if (clientfd < 0) {
		std::cerr << "Error accepting connection" << std::endl;
		return 1;
	}
	std::cout << "Connected from : " << clientfd << std::endl;

	//----------------------------
	// รับข้อมูล
	char buffer[1024];
	while (strcmp(buffer, "stop\n") != 0)
	{
		std::string text(buffer);
		text.pop_back();
		std::cout << "BUF : >" << text << "<";
		bzero(buffer, strlen(buffer));
		int nread = recv(clientfd, buffer, sizeof(buffer), 0);
		if (nread < 0) {
			std::cerr << "Error receiving data" << std::endl;
			return 1;
	}

	// ส่งข้อมูลกลับ
	send(clientfd, buffer, nread, 0);
	}
	//----------------------------

	// ปิดซ็อกเก็ต
	close(clientfd);
	close(sockfd);

	return 0;
}