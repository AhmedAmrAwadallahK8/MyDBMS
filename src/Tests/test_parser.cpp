#include <iostream>
#include <string>

#include "test_parser.h"
#include "..\QueryLanguage\parser.h"

void Test_Parser::test(){
    test_basic();

    std::cout << "All Tests Done";
}

void Test_Parser::test_basic(){

    Parser p("Hello my name is Ahmed;");
    std::string token = "";

    while(token != "END"){
        p.get_token();
    }
}