#ifndef NODE_BLOCK_H
#define NODE_BLOCK_H

#include <vector>
#include "node.h"
#include "abstract_block.h"

class Node_Block: public Abstract_Block {
    protected:
        Abstract_Block *child_block;
        std::vector<Node> node_vec;
    public:
        Node_Block();
        ~Node_Block();
        Abstract_Block* get_child_block();
};

#endif