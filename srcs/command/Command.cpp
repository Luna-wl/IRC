#include "Command.hpp"

Command::Command(Server * srv)
{
	_srv = srv;
}

Command::~Command()
{
	
}

std::vector<std::string> commaSeperator(std::string arg)
{
	std::vector<std::string> ret;
	size_t pos = 0;
	while ((pos = arg.find(",")) != std::string::npos)
	{
		ret.push_back(arg.substr(0, pos));
		arg.erase(0, pos + 1);
	}
	ret.push_back(arg.substr(0, pos));
	return (ret);
}