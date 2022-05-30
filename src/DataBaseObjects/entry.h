#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry{
    protected:
        std::string type;
        int int_data;
        double dbl_data;
        char char_data;
        std::string str_data;
    public:
        Entry();
        ~Entry();
};

#endif