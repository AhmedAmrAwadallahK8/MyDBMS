
#include "entry.h"

Entry::Entry(){}

Entry::Entry(int input):
    int_entry(input),
    next_entry(nullptr),
    type(0)
    {}

Entry::Entry(double input):
    dbl_entry(input),
    next_entry(nullptr),
    type(1)
    {}

Entry::Entry(char input):
    char_entry(input),
    next_entry(nullptr),
    type(2)
    {}

Entry::Entry(std::string input):
    str_entry(input),
    next_entry(nullptr),
    type(3)
    {}

Entry::~Entry(){};

Entry& Entry::operator= (const Entry& entry){
    next_entry = nullptr;
    type = entry.type;
    switch(type){
        case Entry::INT:
            int_entry = entry.int_entry;
            break;
        case Entry::DOUBLE:
            char_entry = entry.char_entry;
            break;
        case Entry::CHAR:
            char_entry = entry.char_entry;
            break;
        case Entry::STRING:
            str_entry = entry.str_entry;
            break;
    }
    return *this;
}

void Entry::print_entry(){
    switch(type){
        case INT:
            std::cout << int_entry;
            break;
        case DOUBLE:
            std::cout << dbl_entry;
            break;
        case CHAR:
            std::cout << char_entry;
            break;
        case STRING:
            std::cout << str_entry;
            break;
        default:
            std::cout << "Unknown Type";
    }
}

int Entry::get_int(){
    return int_entry;
}
double Entry::get_dbl(){
    return dbl_entry;
}
char Entry::get_char(){
    return char_entry;
}
std::string Entry::get_str(){
    return str_entry;
}
Entry* Entry::get_next_entry_ptr(){
    return next_entry;
}

void Entry::set_next_entry_ptr(Entry* input){
    next_entry = input;
}

void Entry::test(){
    Entry d = Entry("Hello");
    Entry c = Entry('a');
    Entry b = Entry(2.3);
    Entry a = Entry(2);

    a.set_next_entry_ptr(&b);
    b.set_next_entry_ptr(&c);
    c.set_next_entry_ptr(&d);

    /* Testing Normal Functions */
    std::cout << "Int Test|" << " Value: " << a.get_int() << std::endl;
    std::cout << "Double Test|" << " Value: " << b.get_dbl() << std::endl;
    std::cout << "Char Test|" << " Value: " << c.get_char() << std::endl;
    std::cout << "String Test|" << " Value: " << d.get_str() << std::endl;

    /* Testing pointer relationships */
    std::cout << "A Test| Address: " << &a << " Next Address: " << a.get_next_entry_ptr()  << std::endl;
    std::cout << "B Test| Address: " << &b << " Next Address: " << b.get_next_entry_ptr()  << std::endl;
    std::cout << "C Test| Address: " << &c << " Next Address: " << c.get_next_entry_ptr()  << std::endl;
    std::cout << "D Test| Address: " << &d << " Next Address: " << d.get_next_entry_ptr()  << std::endl;
}


