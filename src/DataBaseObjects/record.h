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
        Record();
        Record(std::vector<int> table_attributes, std::vector<std::string> &entries);
        ~Record();
        Record(const Record& rec);

        Record& operator= (const Record& rec);
        void subset_record(std::vector<int> subset);
        std::vector<Entry*> get_all_entries();
        void delete_unused_entries(std::vector<Entry*> entries);

        Entry* add_new_entry(int entry_type, std::string data);
        void add_new_entry(Entry* entry);
        Entry* get_head_ptr();

        void print_record();


        void static test();
};

#endif