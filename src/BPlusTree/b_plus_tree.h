#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "node_block.h"

class B_Plus_Tree{
    protected:
        Node_Block* root_node_block;
    public:
        B_Plus_Tree();
        ~B_Plus_Tree();

};

#endif