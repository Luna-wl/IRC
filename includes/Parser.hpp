#ifndef PARSER_HPP
# define PARSER_HPP

# include <sstream>

# include "Client.hpp"
# include "Server.hpp"
# include "Command.hpp"

class Parser
{
    private:
        Server*  _srv;
        std::map<std::string, Command *> _cmd;
    public:
        Parser(Server * srv);
        ~Parser();
        void analyze(Client *client, std::string &text);
		void welcomeMessage(Client *client);
};

#endif