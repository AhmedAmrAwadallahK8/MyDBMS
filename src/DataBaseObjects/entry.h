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

    void static test();
};



#endif