#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

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
    public:
        Table(std::string input_name, std::vector<std::string> input_attributes, 
                std::vector<int> input_flags);
        ~Table();

        void insert_record(Record* input_record);
        void print_table();

        friend class test_table;
};

#endif