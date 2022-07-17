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
        int i = 0;
        for(std::string attr: input_attributes){
            attr_to_ind_map.insert(std::pair<std::string, int>(attr, i));
            i++;
        }
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

std::vector<std::string> Table::get_attribute_names(){
    return attribute_names;
}

std::vector<int> Table::get_attribute_flags(){
    return attribute_flags;
}

std::string Table::get_table_name(){
    return table_name;
}

std::vector<int> Table::get_subset_flags(std::vector<std::string> attr_subset){
    std::vector<int> subset_flags;
    for(std::string attr: attr_subset){
        int type_ind = attr_to_ind_map[attr];
        subset_flags.push_back(attribute_flags[type_ind]);
    }
    return subset_flags;
}

void Table::insert_record_vector(std::vector<Record*> input_records){
    for(Record* rec: input_records){
        insert_record(rec);
    }
}

void Table::subset_record_vector(std::vector<Record*> input_records, std::vector<std::string> attr_subset){
    for(Record* rec: input_records){
        subset_record(rec, attr_subset);
    }
}

void Table::subset_record(Record* input_record, std::vector<std::string> attr_subset){
    std::vector<int> index_subset;
    for(std::string attr: attr_subset){
        int index = attr_to_ind_map[attr];
        index_subset.push_back(index);
    }
    input_record->subset_record(index_subset);
}

std::vector<Record*> Table::get_all_records(){
    std::vector<Record*> records;
    switch(prim_key_type){
        case Entry::INT:
            records = int_tree->get_all_records();
            break;
        case Entry::DOUBLE:
            records = dbl_tree->get_all_records();
            break;
        case Entry::CHAR:
            records = char_tree->get_all_records();
            break;
        case Entry::STRING:
            records = str_tree->get_all_records();
            break;
    }
    return records; 
}

std::vector<Record*> Table::get_copy_of_all_records(){
    std::vector<Record*> real_records = get_all_records();
    std::vector<Record*> copy_records;
    for(Record* rec: real_records){
        Record* temp = new Record();
        *temp = *rec;
        copy_records.push_back(temp);
    }
    return copy_records;
}

std::vector<Record*> Table::get_all_records_subset(std::vector<std::string> attr_subset){
    std::vector<Record*> records = get_copy_of_all_records();
    subset_record_vector(records, attr_subset);
    return records;
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