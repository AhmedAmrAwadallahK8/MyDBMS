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
        void print_record();
};

Record::Record(std::vector<int> table_attributes, std::vector<std::string> &entries):
    table_attributes(table_attributes)
{
    std::vector<int>::iterator table_attr_iterator = table_attributes.begin();
    std::vector<std::string>::iterator entries_iterator = entries.begin();

    head_ptr = add_new_entry(*table_attr_iterator, *entries_iterator);
    table_attr_iterator++;
    entries_iterator++;

    Entry* curr_entry = head_ptr;
    for(;table_attr_iterator != table_attributes.end() && entries_iterator != entries.end(); table_attr_iterator++, entries_iterator++){
        curr_entry->next_entry = add_new_entry(*table_attr_iterator, *entries_iterator);
        curr_entry = curr_entry->next_entry;
    }
}

Record::~Record(){
    Entry* curr_entry = head_ptr;
    Entry* next_entry = head_ptr->next_entry;
    while(curr_entry != nullptr){
        delete curr_entry;
        curr_entry = next_entry;
        next_entry = curr_entry->next_entry;
    }
}

void Record::print_record(){
    Entry* curr_entry = head_ptr;
    while(curr_entry!=nullptr){
        curr_entry->print_entry();
        curr_entry = curr_entry->next_entry;
        std::cout << "\t\t";
    }
    std::cout << std::endl;
}

Entry* Record::add_new_entry(int entry_type, std::string data){
    int int_input;
    double dbl_input;
    char char_input;
    std::string str_input;
    switch(entry_type){
        case(Entry::INT):
            int_input = std::stoi(data);
            return new Entry(int_input);
            break;
        case(Entry::DOUBLE):
            dbl_input = std::stod(data);
            return new Entry(dbl_input);
            break;
        case(Entry::CHAR):
            char_input = (data).data()[0];
            return new Entry(char_input);
            break;
        case(Entry::STRING):
            str_input = (std::string)(data);
            return new Entry(str_input);
            break;
        default:
            return nullptr;
    }
}

void test_record(){
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record a = Record(attr, entries);
    std::cout << "Int Field\tDouble Field\tChar Field\tString Field\n";
    a.print_record();
}

#endif