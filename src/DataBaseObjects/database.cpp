#include <vector>
#include <map>
#include <string>

#include "database.h"
#include "table.h"

Database::Database(std::string input_name):
    database_name(input_name)
    {}

Database::~Database(){}

/* TODO: Handle new tables with a name already in the database*/
void Database::create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types){
    Table* new_table = new Table(table_name, attribute_names, attributes_types);
    tables.insert(std::pair<std::string, Table*>(table_name, new_table));
}

void Database::insert_into_table(std::string table_name, Record* input_record){
    Table* specified_table = tables[table_name];
    specified_table->insert_record(input_record);
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