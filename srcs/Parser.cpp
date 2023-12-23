#include "Parser.hpp"

Parser::Parser( void )
{

}

Parser::~Parser( void )
{

}

void Parser::invoke( std::string command )
{
	if (command == "HELP") {
		std::cout << "using HELP command" << std::endl;
	}
}
