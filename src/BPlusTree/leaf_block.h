#ifndef LEAF_BLOCK_H
#define LEAF_BLOCK_H

#include "abstract_block.h"
#include "leaf_node.h"

class Leaf_Block: public Abstract_Block{
    protected:
        Leaf_Block *next_leaf_block;
        Leaf_Block *prev_leaf_block;
        std::vector<Leaf_Node> nodes;
    public:
        Leaf_Block();
        ~Leaf_Block();
};

#endif