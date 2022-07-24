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

bool Table::attributes_exist(std::vector<std::string> select_attr){
    bool attr_exists = true;
    for(std::string attr: select_attr){
        attr_exists = std::find(attribute_names.begin(), attribute_names.end(), attr) != attribute_names.end();
        if(attr_exists == false){
            return attr_exists;
        }
    }
    return attr_exists;
}

void Table::expected_attributes_to_exist(){
    std::cout << "Encountered one or more attributes that do not exist in the table.\n";
}

bool Table::valid_attribute_size(std::vector<std::string> select_attr){
    if(select_attr.size() <= attribute_names.size()){
        return true;
    }
    else{
        return false;
    }

}

void Table::expected_valid_attribute_size(){
    std::cout << "Encountered an attribute list longer than this table.\n";

}

bool Table::valid_attribute_list(std::vector<std::string> select_attr){
    if(valid_attribute_size(select_attr) && attributes_exist(select_attr)){
        return true;
    }
    else if(valid_attribute_size(select_attr)){
        expected_attributes_to_exist();
        return false;
    }
    else if(attributes_exist(select_attr)){
        expected_valid_attribute_size();
        return false;
    }
    else{
        return false;
    }
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

void Table::insert_record_vector(std::vector<Record*> input_records, std::vector<std::string> expression_seq){
    std::string attribute = expression_seq[0];
    int attribute_ind = attr_to_ind_map[attribute];
    int attribute_type = attribute_flags[attribute_ind];
    std::string where_op = expression_seq[1];
    std::string value = expression_seq[2];
    bool valid_record = false;
    for(Record* rec: input_records){
        valid_record = false;
        Entry* entry = rec->get_entry_at_index(attribute_ind);
        if(greater_than(where_op)){
            if(attribute_type == Entry::INT){
                int entry_value = entry->get_int();
                int int_value = std::stoi(value);
                if(entry_value > int_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }
            }
            else if (attribute_type == Entry::DOUBLE){
                double entry_value = entry->get_dbl();
                double dbl_value = std::stod(value);
                if(entry_value > dbl_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::CHAR){
                char entry_value = entry->get_char();
                char char_value = (value).data()[0];
                if(entry_value > char_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::STRING){
                std::string entry_value = entry->get_str();
                std::string str_value = value;
                if(entry_value > str_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
        }
        else if(less_than(where_op)){
            if(attribute_type == Entry::INT){
                int entry_value = entry->get_int();
                int int_value = std::stoi(value);
                if(entry_value < int_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }
            }
            else if (attribute_type == Entry::DOUBLE){
                double entry_value = entry->get_dbl();
                double dbl_value = std::stod(value);
                if(entry_value < dbl_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::CHAR){
                char entry_value = entry->get_char();
                char char_value = (value).data()[0];
                if(entry_value < char_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::STRING){
                std::string entry_value = entry->get_str();
                std::string str_value = value;
                if(entry_value < str_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }

        }
        else if(equals(where_op)){
            if(attribute_type == Entry::INT){
                int entry_value = entry->get_int();
                int int_value = std::stoi(value);
                if(entry_value == int_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }
            }
            else if (attribute_type == Entry::DOUBLE){
                double entry_value = entry->get_dbl();
                double dbl_value = std::stod(value);
                if(entry_value == dbl_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::CHAR){
                char entry_value = entry->get_char();
                char char_value = (value).data()[0];
                if(entry_value == char_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }

            }
            else if (attribute_type == Entry::STRING){
                std::string entry_value = entry->get_str();
                std::string str_value = value;
                if(entry_value == str_value){
                    valid_record = true;
                }
                else{
                    delete rec;
                }
            }
        }
        if(valid_record){
            insert_record(rec);
        }
    }
}

bool Table::greater_than(std::string string_op){
    if(string_op == ">"){
        return true;
    }
    else{
        return false;
    }

}

bool Table::less_than(std::string string_op){
    if(string_op == "<"){
        return true;
    }
    else{
        return false;
    }

}

bool Table::equals(std::string string_op){
    if(string_op == "="){
        return true;
    }
    else{
        return false;
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