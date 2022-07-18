#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>
#include <map>

#include "../BPlusTree/b_plus_tree.h"

class Table{
    protected:
        std::string table_name;
        std::vector<std::string> attribute_names;
        std::vector<int> attribute_flags;
        int prim_key_type;
        B_Plus_Tree<int>* int_tree;
        B_Plus_Tree<double>* dbl_tree;
        B_Plus_Tree<char>* char_tree;
        B_Plus_Tree<std::string>* str_tree;
        std::map<std::string, int> attr_to_ind_map;
    public:
        Table(std::string input_name, std::vector<std::string> input_attributes, 
                std::vector<int> input_flags);
        ~Table();

        void insert_record(Record* input_record);
        void insert_record_vector(std::vector<Record*> input_records);
        void subset_record(Record* input_record, std::vector<std::string> attr_subset);
        void subset_record_vector(std::vector<Record*> input_records, std::vector<std::string> attr_subset);
        void create_and_insert_record(std::vector<std::string> input_strings);
        void print_table();
        std::vector<Record*> get_all_records();
        std::vector<Record*> get_copy_of_all_records();
        std::vector<Record*> get_all_records_subset(std::vector<std::string> attr_subset);
        std::string get_table_name();
        std::vector<std::string> get_attribute_names();
        std::vector<int> get_attribute_flags();
        std::vector<int> get_subset_flags(std::vector<std::string> attr_subset);
        bool attributes_exist(std::vector<std::string> select_attr);
        void expected_attributes_to_exist();
        bool valid_attribute_size(std::vector<std::string> select_attr);
        void expected_valid_attribute_size();
        bool valid_attribute_list(std::vector<std::string> select_attr);

        friend class test_table;
};

#endif