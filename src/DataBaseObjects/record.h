#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "entry.h"

//insert into classroom values ('Packard', '101', '500');

template<typename Type>
class Record{
    protected:
        std::vector<std::string> attributes;
        Entry<Type> *primary_key;
    public:
        Record();
        ~Record();
        build_record(std::vector<std::string> entry_list);
        is_int();
        is_double();
        is_char();
        is_string();
        add_entry();
};

#endif