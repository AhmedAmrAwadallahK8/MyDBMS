#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

class Lexer{
    protected:
        std::string text;
    public:
        Lexer(std::string input);
        ~Lexer();
        
        std::vector<std::string> lex_text();
};

#endif