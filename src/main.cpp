#include <iostream>

#include "DataBaseObjects\int_entry.h"

int main(){
    Int_Entry a(2);
    // Entry b(2.0);
    // Entry c('a');
    // Entry d("Hello");

    std::cout << "Int Test| Type: " << a.get_type() << " Value: " << a.get_data() << std::endl;
    // std::cout << "Dbl Test: " << b.get_data() << std::endl;
    // std::cout << "Char Test: " << c.get_data() << std::endl;
    // std::cout << "String Test: " << d.get_data() << std::endl;


    std::cout << "Program Execution Complete";
}