#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

#include "node.h"
#include "abstract_node_block.h"

class Node_Block: public Abstract_Node_Block {
    protected:
        Node_Block *child_node_block;
        std::vector<Node> node_vec;
    public:
        Node_Block();
        ~Node_Block();
        Node_Block* get_child_node_block();
};

#endif