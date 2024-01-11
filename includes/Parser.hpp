#ifndef PARSER_HPP
# define PARSER_HPP

# include "Client.hpp"
# include "Server.hpp"

class Parser
{
    private:
        // Server*  _srv;
        // Command  _cmd;
    public:
        void analyze(Client &client, std::string &text);
};

#endif