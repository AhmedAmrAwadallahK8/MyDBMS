#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <string>

#include <b_plus_tree.h>

class Table{
    protected:
        std::string table_name;
        std::vector<std::string> attributes;
        B_Plus_Tree *tree;
    public:
        Table();
        ~Table();
};

#endif