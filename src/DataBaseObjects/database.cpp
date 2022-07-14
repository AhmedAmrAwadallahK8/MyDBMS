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

/* TODO: Handle new tables with a name already in the database*/
void Database::create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types){
    Table* new_table = new Table(table_name, attribute_names, attributes_types);
    tables.insert(std::pair<std::string, Table*>(table_name, new_table));
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