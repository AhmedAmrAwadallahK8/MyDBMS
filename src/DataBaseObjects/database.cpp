#include <vector>
#include <map>
#include <string>

#include "database.h"
#include "table.h"

Database::Database(std::string input_name):
    database_name(input_name)
    {}

Database::~Database(){
    Table* curr_table;
    for(auto pair: tables){
        curr_table = pair.second;
        delete curr_table;
    }
}

void Database::drop_table(std::string table_name){
    if(table_exists(table_name)){
        Table* table_to_be_dropped = tables[table_name];
        tables.erase(table_name);
        delete table_to_be_dropped;
        table_dropped();
    }
    else{
        expected_table_to_exist();
    }
}

void Database::create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types){
    if(table_exists(table_name)){
        expected_table_to_not_exist();
    }
    else{
        Table* new_table = new Table(table_name, attribute_names, attributes_types);
        tables.insert(std::pair<std::string, Table*>(table_name, new_table));
    }
}

Table* Database::execute_select(std::string table_name, std::vector<std::string> selected_attributes){
    Table* new_table;
    Table* from_table = tables[table_name];
    if(select_all(selected_attributes)){
        std::vector<int> attr_flags = from_table->get_attribute_flags();
        std::vector<std::string> attr_names = from_table->get_attribute_names();
        new_table = new Table(table_name, attr_names, attr_flags);
        transfer_records(from_table, new_table);
        return new_table;
    }
    else{
        /*TODO: Check if identifiers even exist in table*/
        std::vector<int> sub_flags = from_table->get_subset_flags(selected_attributes);
        new_table = new Table(table_name, selected_attributes, sub_flags);
        transfer_records_subset(from_table, new_table, selected_attributes);
        return new_table;
    }
}

void Database::transfer_records_subset(Table* orig_table, Table* new_table, std::vector<std::string> attr_subset){
    std::vector<Record*> copy = orig_table->get_all_records_subset(attr_subset);
    new_table->insert_record_vector(copy);
}

void Database::transfer_records(Table* orig_table, Table* new_table){
    std::vector<Record*> copy = orig_table->get_copy_of_all_records();
    new_table->insert_record_vector(copy);
}

bool Database::select_all(std::vector<std::string> selected_attributes){
    if((selected_attributes.size() == 1) && selected_attributes[0] == "*"){
        return true;
    }
    else{
        return false;
    }
}

void Database::insert_into_table(std::string table_name, Record* input_record){
    Table* specified_table = tables[table_name];
    specified_table->insert_record(input_record);
}

void Database::insert_into_table(std::string table_name, std::vector<std::string> input_strings){
    Table* t = tables[table_name];
    t->create_and_insert_record(input_strings);
}

void Database::insert_into_table_if_exists(std::string table_name, std::vector<std::string> input_strings){
    if(table_exists(table_name)){
        insert_into_table(table_name, input_strings);
    }
    else{
        std::cout << "Table with name " << table_name << " does not exist.\n";
    }
}

bool Database::table_exists(std::string table_name){
    if(tables.count(table_name) == 1){
        return true;
    }
    else{
        return false;
    }

}

void Database::print_table(std::string table_name){
    Table* specified_table = tables[table_name];
    specified_table->print_table();
}

void Database::print_tables(){
    std::string table_name = "";
    std::cout << "Tables\n";
    for(const auto& pair: tables){
        table_name = pair.first;
        std::cout << "  " << table_name << "\n";
    }
}

void Database::expected_table_to_exist(){
    std::cout << "Specified table does not exist in the database.\n";
}

void Database::expected_table_to_not_exist(){
    std::cout << "Specfied table already exists in the database.\n";
}

void Database::table_dropped(){
    std::cout << "Dropped the specified table.\n";
}