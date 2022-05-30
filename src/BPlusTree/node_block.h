#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

#include "node.h"

class Node_Block{
    protected:
        int block_size;
        bool is_leaf;
        Node *block_head;
        Node_Block *next_node_block;
        Node_Block *prev_node_block;
        Node_Block *child_node_block;
        Node_Block *root_node_block;
    public:
        Node_Block* get_next_node_block();
        Node_Block* get_prev_node_block();
        Node_Block* get_child_node_block();
        Node_Block* get_root_node_block();
        bool is_leaf();


};

#endif