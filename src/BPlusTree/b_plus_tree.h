#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "abstract_block.h"

class B_Plus_Tree{
    protected:
        Abstract_Block* root_block;
    public:
        B_Plus_Tree();
        ~B_Plus_Tree();

};

#endif