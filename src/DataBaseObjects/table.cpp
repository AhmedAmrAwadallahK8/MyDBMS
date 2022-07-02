#include <vector>
#include <string>

#include "table.h"
#include "../BPlusTree/b_plus_tree.h"

Table::Table(std::string input_name, std::vector<std::string> input_attributes, std::vector<int> input_flags):
    table_name(input_name),
    attribute_names(input_attributes),
    attribute_flags(input_flags)
    {
        
    }