#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <typeinfo>
#include <iostream>

/* Future note this probably wasn't an optimal use case for struct */
struct Entry{
    union{
        int int_entry;
        double dbl_entry;
        char char_entry;
        std::string str_entry;
    };
    Entry *next_entry;
    int type;

    enum type_flags{
        INT = 0,
        DOUBLE = 1,
        CHAR = 2,
        STRING = 3
    };

    Entry(int input);
    Entry(double input);
    Entry(char input);
    Entry(std::string input);

    ~Entry();

    void print_entry();
};

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

void test_entry(){
    Entry d = Entry("Hello");
    Entry c = Entry('a');
    Entry b = Entry(2.3);
    Entry a = Entry(2);

    a.next_entry = &b;
    b.next_entry = &c;
    c.next_entry = &d;

    /* Testing Normal Functions */
    std::cout << "Int Test|" << " Value: " << a.int_entry << std::endl;
    std::cout << "Double Test|" << " Value: " << b.dbl_entry << std::endl;
    std::cout << "Char Test|" << " Value: " << c.char_entry << std::endl;
    std::cout << "String Test|" << " Value: " << d.str_entry << std::endl;

    /* Testing pointer relationships */
    std::cout << "A Test| Address: " << &a << " Next Address: " << a.next_entry  << std::endl;
    std::cout << "B Test| Address: " << &b << " Next Address: " << b.next_entry  << std::endl;
    std::cout << "C Test| Address: " << &c << " Next Address: " << c.next_entry  << std::endl;
    std::cout << "D Test| Address: " << &d << " Next Address: " << d.next_entry  << std::endl;
}

#endif