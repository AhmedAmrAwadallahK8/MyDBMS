#ifndef ENTRY_H
#define ENTRY_H

#include <string>

class Entry{
    protected:
        std::string type;
    public:
        Entry(std::string type);
        ~Entry();
        std::string get_type();
};

#endif