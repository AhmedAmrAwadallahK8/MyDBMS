#ifndef B_PLUS_TREE_H
#define B_PLUS_TREE_H

#include "entry.h"
#include "record.h"
#include "node_block.h"

class B_Plus_Tree{
    protected:
        Node_Block* root_block;
        int type_flag;
    public:
        B_Plus_Tree();
        ~B_Plus_Tree();

        void insert(Record* input_record);

};

#endif