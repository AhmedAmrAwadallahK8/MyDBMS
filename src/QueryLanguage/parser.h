#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

class Parser{
    protected:
        std::vector<std::string> token_vec;
        std::vector<std::string>::const_iterator token_iter;
    public:
        Parser(std::string input);
        ~Parser();
        Parser& operator= (Parser&& x);

        std::string get_token();
        void print_token_vec();
};

#endif 