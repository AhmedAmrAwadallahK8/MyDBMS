#include <vector>
#include <map>
#include <string>

#include "database.h"
#include "table.h"

Database::Database(std::string input_name):
    database_name(input_name)
    {}

Database::~Database(){}

void Database::create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types){
    Table* new_table = new Table(table_name, attribute_names, attributes_types);
    tables.insert(std::pair<std::string, Table*>(table_name, new_table));
}