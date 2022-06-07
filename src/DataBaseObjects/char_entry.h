#ifndef CHAR_ENTRY_H
#define CHAR_ENTRY_H

#include "entry.h"

class Char_Entry: public Entry{
    protected:
        char data;
    public:
        Char_Entry(char c);
        ~Char_Entry();

        char get_data();
};

#endif