#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "abstract_block.h"
#include "entry.h"

class B_Plus_Tree{
    protected:
        Abstract_Block* root_block;
        int type_flag;
    public:
        B_Plus_Tree();
        ~B_Plus_Tree();

        void insert(Entry* primary_key);

};

#endif