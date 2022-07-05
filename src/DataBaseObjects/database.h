#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <map>
#include <string>

#include "table.h"

class Database{
    protected:
        std::string database_name;
        std::map<std::string, Table*> tables;
    public:
        Database(std::string input_name);
        ~Database();

        void create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types);
        void insert_into_table(std::string table_name, Record* input_record);
        Table* get_table_by_name();
        void print_table();

        friend class Test_Database;
};

#endif