#include <string>

#include "parser.h"
#include "lexer.h"

Parser::Parser(std::string input):
    text(input)
    {
        Lexer temp_lex(input);
        token_vec = temp_lex.lex_text();
    }

Parser::~Parser(){}

std::string Parser::get_token(){
    return "";    
}
