#include "Command.hpp"

Command::Command(Server * srv)
{
	_srv = srv;
}

Command::~Command()
{
	
}

Test::Test(Server * srv) : Command(srv) {}
Test::~Test() {}

void Test::execute(Client * client, std::vector<std::string> & args)
{
	(void) args;
	(void) client;
	std::cout << "test : " << _srv->time(0) << std::endl;
	std::cout << "test : " << _srv->time(1) << std::endl;
	std::cout << "test : " << _srv->time(2) << std::endl;
}