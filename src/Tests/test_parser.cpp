#include <iostream>
#include <string>

#include "test_parser.h"
#include "..\QueryLanguage\parser.h"

//Tests both lexer and parser as one does not exist without the other*/
void Test_Parser::test(){
    test_lexer();


    std::cout << "All Tests Done\n";
}

void Test_Parser::test_lexer(){

    Parser p("\'Hello\' * (my, my2) name.is \"Ahmed\";");
    p.print_token_vec();

//    while(token != "END"){
//        p.get_token();
//    }
}