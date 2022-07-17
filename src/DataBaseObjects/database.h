#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <map>
#include <string>

#include "table.h"

class Record;

class Database{
    protected:
        std::string database_name;
        std::map<std::string, Table*> tables;
    public:
        Database(std::string input_name);
        ~Database();

        void create_table(std::string table_name, std::vector<std::string> attribute_names, std::vector<int> attributes_types);
        void insert_into_table(std::string table_name, Record* input_record);
        void insert_into_table(std::string table_name, std::vector<std::string> input_strings);
        void insert_into_table_if_exists(std::string table_name, std::vector<std::string> input_strings);
        Table* get_table_by_name();
        void print_table(std::string table_name);
        void print_tables();
        void drop_table(std::string table_name);
        Table* execute_select(std::string table_name, std::vector<std::string> selected_attributes);
        bool select_all(std::vector<std::string> selected_attributes);
        void transfer_records(Table* orig_table, Table* new_table);
        void transfer_records_subset(Table* orig_table, Table* new_table, std::vector<std::string> attr_subset);
        std::vector<Record*> get_copy_of_all_records(std::vector<Record*> records);

        bool table_exists(std::string table_name);
        void expected_table_to_exist();
        void expected_table_to_not_exist();
        void table_dropped();

        friend class Test_Database;
};

#endif