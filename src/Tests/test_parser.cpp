#include <iostream>
#include <string>

#include "test_parser.h"
#include "..\QueryLanguage\parser.h"

//Tests both lexer and parser as one does not exist without the other*/
void Test_Parser::test(){
    test_lexer();
    test_get_token();
    std::cout << "All Tests Done\n";
}

void Test_Parser::test_lexer(){
    Parser p("\'Hello\' * (my, my2) name.is \"Ahmed\";");
    p.print_token_vec();
}

void Test_Parser::test_get_token(){
    Parser p("\'Hello\' * (my, my2) name.is \"Ahmed\";");
    std::string curr_token = p.get_token();
    while(curr_token != "END TOKEN"){
        std::cout << curr_token << std::endl;
        curr_token = p.get_token();
    }
}