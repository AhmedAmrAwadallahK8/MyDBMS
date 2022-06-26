#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

#include <b_plus_tree.h>

class Table{
    protected:
        std::string table_name;
        std::vector<std::string> attribute_names;
        std::vector<int> attribute_flags;
        B_Plus_Tree *root;
    public:
        Table();
        ~Table();
};

#endif