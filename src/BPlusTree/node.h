#ifndef NODE_H
#define NODE_H

#include "entry.h"
#include "abstract_node.h"
#include "abstract_block.h"

class Node: public Abstract_Node {
    protected:
        Abstract_Block *child_block_ptr;
    public:
        Node();
        ~Node();
        Abstract_Block* get_child();  
};

#endif