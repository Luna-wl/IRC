#ifndef PARSER_HPP
# define PARSER_HPP

# include <sstream>

# include "Server.hpp"
# include "Client.hpp"
# include "Command.hpp"
class Command;

class Parser
{
    private:
        Server*  _srv;
        std::map<std::string, Command *> _cmd;
    public:
        Parser(Server * srv);
        ~Parser();
        void analyze(Client *client, std::string &text);
};

#endif