#ifndef RECORD_H
#define RECORD_H

#include <vector>
#include <string>

#include "entry.h"

//insert into classroom values ('Packard', '101', '500');

class Record{
    public:
        Entry* primary_key_ptr;
    //public:
        enum attribute_flags{
            INT = 0,
            DOUBLE = 1,
            CHAR = 2,
            STRING = 3
        };
        Record(std::vector<int> &table_attributes, std::vector<std::string> &entries);
        ~Record();

        Entry* add_new_entry(int entry_type, std::string data);
};

Record::Record(std::vector<int> &table_attributes, std::vector<std::string> &entries){
    std::vector<int>::iterator table_attr_iterator = table_attributes.begin();
    std::vector<std::string>::iterator entries_iterator = entries.begin();

    primary_key_ptr = add_new_entry(*table_attr_iterator, *entries_iterator);
    table_attr_iterator++;
    entries_iterator++;

    Entry* curr_entry = primary_key_ptr;
    for(;table_attr_iterator != table_attributes.end() && entries_iterator != entries.end(); table_attr_iterator++, entries_iterator++){
        curr_entry->next_entry = add_new_entry(*table_attr_iterator, *entries_iterator);
        curr_entry = curr_entry->next_entry;
    }
}

Record::~Record(){}

Entry* Record::add_new_entry(int entry_type, std::string data){
    int int_input;
    double dbl_input;
    char char_input;
    std::string str_input;
    switch(entry_type){
        case(INT):
            int_input = std::stoi(data);
            return new Entry(int_input);
            break;
        case(DOUBLE):
            dbl_input = std::stod(data);
            return new Entry(dbl_input);
            break;
        case(CHAR):
            char_input = (data).data()[0];
            return new Entry(char_input);
            break;
        case(STRING):
            str_input = (std::string)(data);
            return new Entry(str_input);
            break;
        default:
            return nullptr;
    }
}

#endif