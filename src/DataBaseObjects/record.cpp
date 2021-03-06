#include <algorithm>

#include "record.h"

Record::Record():
    head_ptr(nullptr)
    {}

Record::Record(std::vector<int> table_attributes, std::vector<std::string> &entries):
    head_ptr(nullptr),
    table_attributes(table_attributes)
{
    std::vector<int>::iterator table_attr_iterator = table_attributes.begin();
    std::vector<std::string>::iterator entries_iterator = entries.begin();

    head_ptr = add_new_entry(*table_attr_iterator, *entries_iterator);
    table_attr_iterator++;
    entries_iterator++;

    Entry* curr_entry = head_ptr;
    for(;table_attr_iterator != table_attributes.end() && entries_iterator != entries.end(); table_attr_iterator++, entries_iterator++){
        curr_entry->set_next_entry_ptr(add_new_entry(*table_attr_iterator, *entries_iterator));
        curr_entry = curr_entry->get_next_entry_ptr();
    }
}

Record::~Record(){
    Entry* curr_entry = head_ptr;
    Entry* next_entry = head_ptr->get_next_entry_ptr();
    while(curr_entry != nullptr){
        delete curr_entry;
        curr_entry = next_entry;
        if(curr_entry != nullptr){
            next_entry = curr_entry->get_next_entry_ptr();
        }
    }
}

Record& Record::operator=(const Record& rec){
    table_attributes = rec.table_attributes;
    Entry* curr_entry = rec.head_ptr;
    while(curr_entry != nullptr){
        Entry* copy = new Entry();
        *copy = *curr_entry;
        add_new_entry(copy);
        curr_entry = curr_entry->get_next_entry_ptr();
    }
    return *this;
}
//Magistic was here
void Record::subset_record(std::vector<int> subset){
    std::vector<Entry*> entries = get_all_entries();
    head_ptr = nullptr;
    table_attributes.clear();
    std::copy(subset.begin(), subset.end(), back_inserter(table_attributes));
    for(int entry_ind: subset){
        Entry* entry = entries[entry_ind];
        Entry* temp = new Entry();
        *temp = *entry;
        entries[entry_ind] = temp;
        add_new_entry(entry);
    }
    for(int entry_ind: subset){
        entries[entry_ind] = nullptr;
    }
    delete_unused_entries(entries);
}

void Record::delete_unused_entries(std::vector<Entry*> entries){
    for(Entry* entry: entries){
        if(entry!= nullptr){
            delete entry;
        }
    }
}

std::vector<Entry*> Record::get_all_entries(){
    std::vector<Entry*> entry_vec;
    Entry* curr_entry = head_ptr;
    Entry* next_entry;
    while(curr_entry != nullptr){
        next_entry = curr_entry->get_next_entry_ptr();
        curr_entry->set_next_entry_ptr(nullptr);
        entry_vec.push_back(curr_entry);
        curr_entry = next_entry;
    }
    return entry_vec;
}

void Record::add_new_entry(Entry* entry){
    if(head_ptr == nullptr){
        head_ptr = entry;
        return;
    }
    Entry* curr_entry = head_ptr;
    while(curr_entry->get_next_entry_ptr() != nullptr){
        curr_entry = curr_entry->get_next_entry_ptr();
    }
    curr_entry->set_next_entry_ptr(entry);
}

void Record::print_record(){
    Entry* curr_entry = head_ptr;
    while(curr_entry!=nullptr){
        curr_entry->print_entry();
        curr_entry = curr_entry->get_next_entry_ptr();
        std::cout << "\t";
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

Entry* Record::get_head_ptr(){
    return head_ptr;
}

Entry* Record::get_entry_at_index(int ind){
    Entry* curr_entry = head_ptr;
    for(int i = 0; i < ind; i++){
        curr_entry = head_ptr->get_next_entry_ptr();
    }
    return curr_entry;
}

void Record::test(){
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record a = Record(attr, entries);
    std::cout << "Int Field\tDouble Field\tChar Field\tString Field\n";
    a.print_record();
}