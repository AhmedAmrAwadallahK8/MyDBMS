#include <vector>
#include <string>

#include "lexer.h"

Lexer::Lexer(std::string input):
    text(input)
    {}

Lexer::~Lexer(){}

std::vector<std::string> Lexer::lex_text(){
    std::vector<std::string> token_vec;
}