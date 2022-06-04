#ifndef LEAF_NODE_BLOCK_H
#define LEAF_NODE_BLOCK_H

#include "abstract_node_block.h"
#include "leaf_node.h"

class Leaf_Node_Block: public Abstract_Node_Block{
    protected:
        Leaf_Node_Block *next_node_block;
        Leaf_Node_Block *prev_node_block;
        std::vector<Leaf_Node> node_vec;
    public:
        Leaf_Node_Block();
        ~Leaf_Node_Block();
};

#endif