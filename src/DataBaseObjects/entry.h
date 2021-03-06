#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <typeinfo>
#include <iostream>

/* In retrospect Record could just inherit Entry, the methods for getting and 
setting are not required in this case and thus increases code clarity */
class Entry{
    protected:
        union{
            int int_entry;
            double dbl_entry;
            char char_entry;
            std::string str_entry;
        };
        Entry *next_entry;
        int type;
    public:
        enum type_flags{
            INT = 0,
            DOUBLE = 1,
            CHAR = 2,
            STRING = 3
        };
        Entry();
        Entry(int input);
        Entry(double input);
        Entry(char input);
        Entry(std::string input);
        ~Entry();
        Entry& operator= (const Entry& entry);

        int get_int();
        double get_dbl();
        char get_char();
        std::string get_str();
        Entry* get_next_entry_ptr();

        void set_next_entry_ptr(Entry* input);

        void print_entry();

        void static test();
};

#endif