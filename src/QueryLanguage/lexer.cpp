#include <vector>
#include <string>

#include "lexer.h"

Lexer::Lexer(std::string input):
    text(input),
    curr_token("")
    {
        token_vec.push_back("START TOKEN");
    }

Lexer::~Lexer(){}

bool Lexer::is_punctuation(char c){
    if((c==';') | (c==',')| (c=='(')| (c==')') | (c=='.') | (c=='\"') | (c == '\'')){
        return true;
    }
    return false;

}

bool Lexer::is_space(char c){
    if(c==' '){
        return true;
    }
    return false;
}

std::vector<std::string> Lexer::lex_text(){
    for(char c: text){
        if(is_space(c)){
            add_token();
        }
        else if(is_punctuation(c)){
            add_token(); 
            curr_token += c;
            add_token();
        }
        else{
            curr_token += c;
        }
    }
    token_vec.push_back("END TOKEN");
    return token_vec;
}

void Lexer::add_token(){
    if(curr_token.length()>0){
        token_vec.push_back(curr_token);
        curr_token="";
    }
}