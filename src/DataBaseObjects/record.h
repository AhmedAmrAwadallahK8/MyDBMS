#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "entry.h"

//insert into classroom values ('Packard', '101', '500');

class Record{
    protected:
        Entry* head_ptr;
        std::vector<int> table_attributes;
    public:
        Record(std::vector<int> table_attributes, std::vector<std::string> &entries);
        ~Record();

        Entry* add_new_entry(int entry_type, std::string data);
        Entry* get_head_ptr();
        void print_record();

        void static test();
};

#endif