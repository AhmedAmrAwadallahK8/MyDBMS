#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser{
    protected:
        std::string text;
        std::vector<std::string> token_vec;
    public:
        Parser(std::string input);
        ~Parser();

        std::string get_token();
};

#endif 