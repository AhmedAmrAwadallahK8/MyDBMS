#include <vector>
#include <string>

#include "table.h"
#include "../BPlusTree/b_plus_tree.h"

Table::Table(std::string input_name, std::vector<std::string> input_attributes, std::vector<int> input_flags):
    table_name(input_name),
    attribute_names(input_attributes),
    attribute_flags(input_flags),
    prim_key_type(input_flags[0])
    {
        switch(prim_key_type){
            case Entry::INT:
                int_tree = new B_Plus_Tree<int>;
                break;
            case Entry::DOUBLE:
                dbl_tree = new B_Plus_Tree<double>;
                break;
            case Entry::CHAR:
                char_tree = new B_Plus_Tree<char>;
                break;
            case Entry::STRING:
                str_tree = new B_Plus_Tree<std::string>;
                break;
        }
    }

Table::~Table(){
        switch(prim_key_type){
            case Entry::INT:
                delete int_tree;  
                break;
            case Entry::DOUBLE:
                delete dbl_tree;
                break;
            case Entry::CHAR:
                delete char_tree;
                break;
            case Entry::STRING:
                delete str_tree;
                break;
        }
    
}

void Table::insert_record(Record* input_record){
    switch(prim_key_type){
        case Entry::INT:
            int_tree->insert(input_record->get_head_ptr()->get_int(), input_record);
            break;
        case Entry::DOUBLE:
            dbl_tree->insert(input_record->get_head_ptr()->get_dbl(), input_record);
            break;
        case Entry::CHAR:
            char_tree->insert(input_record->get_head_ptr()->get_char(), input_record);
            break;
        case Entry::STRING:
            str_tree->insert(input_record->get_head_ptr()->get_str(), input_record);
            break;
    }
}

void Table::create_and_insert_record(std::vector<std::string> input_strings){
    Record* rec = new Record(attribute_flags, input_strings);
    insert_record(rec);
}

void Table::print_table(){
    for(std::string attr_name: attribute_names){
        std::cout << attr_name << "\t";
    }
    std::cout << std::endl;
    switch(prim_key_type){
        case Entry::INT:
            int_tree->print_tree();
            break;
        case Entry::DOUBLE:
            dbl_tree->print_tree();
            break;
        case Entry::CHAR:
            char_tree->print_tree();
            break;
        case Entry::STRING:
            str_tree->print_tree();
            break;
    }
}