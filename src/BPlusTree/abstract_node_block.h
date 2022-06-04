#ifndef ABSTRACT_NODE_BLOCK_H
#define ABSTRACT_NODE_BLOCK_H

#include <vector>

#include "abstract_node.h"

template <class Type>
class Abstract_Node_Block{
    protected:
        int block_size;
        bool is_full;
        std::vector<Type> node_vec;
    public:
        Abstract_Node_Block();
        ~Abstract_Node_Block();
        
};

#endif