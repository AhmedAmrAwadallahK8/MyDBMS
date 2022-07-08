#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

class Lexer{
    protected:
        std::string text;
        std::string curr_token;
        std::vector<std::string> token_vec;
    public:
        Lexer(std::string input);
        ~Lexer();
        
        std::vector<std::string> lex_text();
        void add_token();
        bool is_punctuation(char c);
        bool is_space(char c);
};

#endif