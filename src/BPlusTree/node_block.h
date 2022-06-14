#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

#include <vector>
#include "node.h"

class Node_Block{
    protected:
        Node_Block *parent_block;
        Node_Block *child_block;
        std::vector<Node> node_vec;
        Node_Block *next_leaf_block;
        Node_Block *prev_leaf_block;
        int block_size;
        bool is_full, is_leaf, is_root;
    public:
        Node_Block();
        ~Node_Block();
        Node_Block* get_child_block();
};

#endif