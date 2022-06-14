
#include "record.h"



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
        next_entry = curr_entry->get_next_entry_ptr();
    }
}

void Record::print_record(){
    Entry* curr_entry = head_ptr;
    while(curr_entry!=nullptr){
        curr_entry->print_entry();
        curr_entry = curr_entry->get_next_entry_ptr();
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

Entry* Record::get_head_ptr(){
    return head_ptr;
}

void Record::test(){
    std::vector<std::string> entries{"2", "2.34", "a", "Hello"};
    std::vector<int> attr{0, 1, 2, 3};
    Record a = Record(attr, entries);
    std::cout << "Int Field\tDouble Field\tChar Field\tString Field\n";
    a.print_record();
}