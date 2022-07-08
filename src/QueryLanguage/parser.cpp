#include <string>
#include <iostream>

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

void Parser::print_token_vec(){
    for(std::string s: token_vec){
        std::cout << s << std::endl;
    }
}
