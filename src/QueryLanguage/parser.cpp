#include <string>
#include <iostream>

#include "parser.h"
#include "lexer.h"

Parser::Parser(std::string input)
    {
        Lexer temp_lex(input);
        token_vec = temp_lex.lex_text();
        token_iter = token_vec.begin();
    }

Parser::~Parser(){}

Parser& Parser::operator= (Parser&& x){
    token_vec=x.token_vec;
    token_iter = token_vec.begin();
    return *this; 
}

std::string Parser::get_token(){
    std::string curr_token = *token_iter;
    if(curr_token != "END TOKEN"){
        token_iter++;
    }
    return curr_token;    
}

void Parser::print_token_vec(){
    for(std::string s: token_vec){
        std::cout << s << std::endl;
    }
}

std::string Parser::look_ahead(int n_tokens){
    std::string future_token = "";
    for(int i = 0; i < n_tokens; i++){
        if(*(token_iter+i) == "END TOKEN"){
            return "END TOKEN";
        }
    } 
    future_token = *(token_iter+n_tokens);
    return future_token;
}
