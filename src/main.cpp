#include <iostream>

#include "DataBaseObjects\int_entry.h"
#include "DataBaseObjects\double_entry.h"
#include "DataBaseObjects\char_entry.h"
#include "DataBaseObjects\string_entry.h"

int main(){
    Int_Entry a(2);
    Double_Entry b(2.3);
    Char_Entry c('a');
    String_Entry d("Hello");

    std::cout << "Int Test| Type: " << a.get_type() << " Value: " << a.get_data() << std::endl;
    std::cout << "Double Test| Type: " << b.get_type() << " Value: " << b.get_data() << std::endl;
    std::cout << "Char Test| Type: " << c.get_type() << " Value: " << c.get_data() << std::endl;
    std::cout << "String Test| Type: " << d.get_type() << " Value: " << d.get_data() << std::endl;


    std::cout << "Program Execution Complete";
}