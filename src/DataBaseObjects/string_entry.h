#ifndef STRING_ENTRY_H
#define STRING_ENTRY_H

#include <string>

#include "entry.h"

class String_Entry: public Entry{
    protected:
        std::string data;
    public:
        String_Entry(std::string s);
        ~String_Entry();

        std::string get_data();
};

#endif